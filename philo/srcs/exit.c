/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:17:53 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/11 17:30:09 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	exit_thread(t_philos *philo, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_philo)
	{
		if (pthread_join(philo[i].t_id, NULL))
			return ;
		i++;
	}
	i = 0;
	while (i < rules->n_philo)
	{
		pthread_mutex_destroy(&(philo->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(philo->action_printing));
	pthread_mutex_destroy(&(philo->eating));
}












