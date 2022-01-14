/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:08:53 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/14 20:59:26 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	print_action(t_philos *philo, t_rules *rules, int philo_id, char *str)
{
	if (!rules->dead)
	{
		pthread_mutex_lock(&(philo->action_printing));
		printf("%lld ", timestamp() - rules->time_start);
		printf("%d", philo_id);
		printf("%s", str);
		pthread_mutex_unlock(&(philo->action_printing));
	}
}


long long	timediff(long long past, long long pres)
{
	return (pres - past);
}
void	sleep_andcheck(long long time, t_rules *rules)
{
	long long timediffs;

	timediffs = timestamp();
	while (!rules->dead)
	{
		if (timediff(timediffs, timestamp()) >= time)
			return ;
		usleep(50);
	}
}
