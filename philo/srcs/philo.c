/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:51:09 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/11 17:54:11 by cmarouf          ###   ########.fr       */
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
	rules->satisfied++;
	pthread_mutex_unlock(&(philo->eating));
	pthread_mutex_unlock(&(philo->forks[philo->fork_left]));
	pthread_mutex_unlock(&(philo->forks[philo->fork_right]));
}

void	*init(void *data)
{
	t_philos 	*philo;
	t_rules 	*rules;

	philo = (t_philos *)data;
	rules = philo->rules;
	rules->dead = 0;
	rules->satisfied = 0;
	init_mutex(philo, rules);
	while (rules->satisfied < 100)
	{
		philo_eat(philo, rules);
		print_action(philo, rules, philo->id, " is sleeping\n");
		usleep(rules->time_to_sleep * 1000);
		print_action(philo, rules, philo->id, " is thinking\n");
	}
	return (NULL);
}

int	philosophers(t_rules *rules)
{
	t_philos	*philo;
	int			i;

	i = 0;
	philo = malloc(sizeof(t_philos) * rules->n_philo);
	if (!philo)
		return (0);
	init_philo(philo, rules);
	rules->time_start = timestamp();
	while (i++ < rules->n_philo)
	{
		if (i % 2 == 0)
			if (pthread_create(&(philo[i].t_id), NULL, init, &(philo[i])))
				return (0);
	}
	i = 0;
	usleep(rules->time_to_eat * 1000);
	while (i++ < rules->n_philo)
	{
		if (i % 2)
			if (pthread_create(&(philo[i].t_id), NULL, init, &(philo[i])))
				return (0);
	}
	exit_thread(philo, rules);
	return (1);
}
