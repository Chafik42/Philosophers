/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:51:09 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/10 16:15:49 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	philo_eat(t_philos *philo, t_rules *rules)
{
		print_action(rules, philo->id, " has taken a fork\n");
		print_action(rules, philo->id, " has taken a fork\n");
		print_action(rules, philo->id, " is eating\n");
}

void	*init(void *data)
{
	t_philos 	*philo;
	t_rules 	*rules;

	philo = data;
	rules = philo->rules;
	rules->dead = 0;
	rules->satisfied = 0;
	while (!rules->satisfied || !rules->dead)
	{
		philo_eat(philo, rules);
		print_action(rules, philo->id, " is sleeping\n");
		usleep(rules->time_to_sleep * 1000);
		print_action(rules, philo->id, " is thinking\n");
	}
	return (NULL);
}

int	philosophers(t_rules *rules)
{
	t_philos	*philo;
	int			i;

	philo = malloc(sizeof(t_philos) * rules->n_philo);
	if (!philo)
		return (0);
	init_philo(philo, rules);
	i = 0;
	rules->time_start = timestamp();
	while (i < rules->n_philo)
	{
		if (pthread_create(&(philo[i].t_id), NULL, init, &(philo[i])))
			return (0);
		i++;
	}
	i = 0;
	while (i < rules->n_philo)
	{
		pthread_join((philo[i].t_id), NULL);
		i++;
	}
	return (1);
}
