/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:51:09 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/12 19:03:05 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	philo_eat(t_philos *philo, t_rules *rules)
{
	pthread_mutex_lock(&(philo->forks[philo->fork_left]));
	print_action(philo, rules, philo->id, " has taken a fork\n");
	pthread_mutex_lock(&(philo->forks[philo->fork_right]));
	print_action(philo, rules, philo->id, " has taken a fork\n");
	pthread_mutex_lock(&(philo->eating));
	print_action(philo, rules, philo->id, " is eating\n");
	philo->lastmeal = timestamp();
	pthread_mutex_unlock(&(philo->eating));
	rules->eating++;
	pthread_mutex_unlock(&(philo->forks[philo->fork_left]));
	pthread_mutex_unlock(&(philo->forks[philo->fork_right]));
}

void	*init(void *data)
{
	t_philos 	*philo;
	t_rules 	*rules;

	philo = (t_philos *)data;
	rules = philo->rules;
	philo->lastmeal = timestamp();
	init_mutex(philo, rules);
	while (!rules->dead)
	{
		philo_eat(philo, rules);
		//if (rules->satisfied)
			//break ;
		print_action(philo, rules, philo->id, " is sleeping\n");
		if (!rules->dead)
			usleep(rules->time_to_sleep * 1000);
		print_action(philo, rules, philo->id, " is thinking\n");
	}
	return (NULL);
}

int	philosophers(t_rules *rules)
{
	t_philos	*philo;

	philo = malloc(sizeof(t_philos) * rules->n_philo);
	if (!philo)
		return (0);
	init_philo(philo, rules);
	rules->time_start = timestamp();
	start_threads(philo, rules);
	check_end(philo, rules);
	exit_thread(philo, rules);
	return (1);
}
