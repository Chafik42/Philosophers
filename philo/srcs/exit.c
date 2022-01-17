/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:17:53 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/17 16:04:49 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	exit_thread(t_philos *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_join(philo[i].t_id, NULL))
			return (0);
		i++;
	}
	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(data->action_printing));
	pthread_mutex_destroy(&(data->eating));
	return (1);
}
