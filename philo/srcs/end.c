/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:39:05 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/13 19:47:28 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	check_end(t_philos *philo, t_rules *rules)
{
	int	i;
	long long	dead_clock;

	while (1)
	{
		i = 0;
		while (i < rules->n_philo && (!rules->dead))
		{
			pthread_mutex_lock(&(philo->eating));
			dead_clock = timestamp() - philo[i].lastmeal;
			if (dead_clock > rules->time_to_die)
			{
				print_action(philo, rules, philo[i].id, " died\n");
				rules->dead = 1;
			}
			pthread_mutex_unlock(&(philo->eating));
		}
		if (rules->dead)
		{
			break ;
		}
	}
}









