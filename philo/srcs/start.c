/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:06:56 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/16 16:54:41 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	start_threads(t_philos *philo, t_data *data, int i)
{
	while (i < data->n_philo)
	{
		if (!(i % 2))
		{
			if (pthread_create(&(philo[i].t_id), NULL, init, &(philo[i])))
				return (0);
			philo[i].lastmeal = timestamp();
		}
		i++;
	}
	usleep(15000);
	i = 0;
	while (i < data->n_philo)
	{
		if (i % 2)
		{
			if (pthread_create(&(philo[i].t_id), NULL, init, &(philo[i])))
				return (0);
			philo[i].lastmeal = timestamp();
		}
		i++;
	}
	return (1);
}
