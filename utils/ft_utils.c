/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:08:53 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/16 16:55:39 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	print_action(t_data *data, int philo_id, char *str)
{
	pthread_mutex_lock(&(data->action_printing));
	if (!data->dead)
	{
		printf("%lld ", timestamp() - data->time_start);
		printf("%d", philo_id + 1);
		printf("%s", str);
	}
	pthread_mutex_unlock(&(data->action_printing));
}

void	sleep_andcheck(long long time, t_data *data)
{
	long long	start_time;
	long long	time_diff;

	start_time = timestamp();
	while (!data->dead)
	{
		time_diff = timestamp() - start_time;
		if (time_diff >= time)
			return ;
		usleep(50);
	}
}
