/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:39:05 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/17 16:36:25 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	one_philosopher(t_philos *philo, t_data *data)
{
	if (data->n_philo == 1)
	{
		if (data->dead)
		{
			pthread_mutex_unlock(&(data->forks[philo->fork_left]));
			pthread_mutex_unlock(&(data->forks[philo->fork_right]));
		}
	}
}

int	check_meal(t_philos *p, t_data *d)
{
	int	i;

	i = 0;
	while ((d->must_eat_count != -1) && i < d->n_philo
		&& p[i].eat_count >= d->must_eat_count)
		i++;
	return (i);
}

int	check_end(t_philos *p, t_data *d, int i)
{
	long long	dead_clock;

	while (1)
	{
		i = 0;
		while (i < d->n_philo && (!d->dead))
		{
			pthread_mutex_lock(&(d->eating));
			dead_clock = timestamp() - p[i].lastmeal;
			if (dead_clock > d->time_to_die)
			{
				print_action(d, p[i].id, " died\n");
				d->dead = 1;
				one_philosopher(p, d);
			}
			pthread_mutex_unlock(&(d->eating));
			i++;
		}
		if (d->dead)
			return (0);
		i = check_meal(p, d);
		if (i == d->n_philo)
			return (1);
	}
}
