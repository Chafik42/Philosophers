/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:08:53 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/15 16:22:25 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	print_action(t_philos *philo, t_rules *rules, int philo_id, char *str)
{
	pthread_mutex_lock(&(philo->action_printing));
	if (!rules->dead)
	{
		printf("%lld ", timestamp() - rules->time_start);
		printf("%d", philo_id + 1);
		printf("%s", str);
	}
	pthread_mutex_unlock(&(philo->action_printing));
}

void	sleep_andcheck(long long time, t_rules *rules)
{
	long long start_time;
	long long time_diff;

	start_time = timestamp();
	while (!rules->dead)
	{
		time_diff = timestamp() - start_time;
		if (time_diff >= time)
			return ;
		usleep(50);
	}
}
