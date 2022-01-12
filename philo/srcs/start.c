/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:06:56 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/12 16:11:32 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	start_threads(t_philos *philo, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_philo)
	{
		if (!(i % 2))
			if (pthread_create(&(philo[i].t_id), NULL, init, &(philo[i])))
				return (0);
		i++;
	}
	usleep(rules->time_to_eat * 1000);
	i = 0;
	while (i < rules->n_philo)
	{
		if ((i % 2))
			if (pthread_create(&(philo[i].t_id), NULL, init, &(philo[i])))
				return (0);
		i++;
	}
	return (1);
}
