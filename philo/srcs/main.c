/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:23:09 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/17 17:13:30 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec / 1000));
}

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->n_philo));
	if (!data->forks)
		return ;
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&(data->action_printing), NULL);
	pthread_mutex_init(&(data->eating), NULL);
}

void	init_philo(t_philos *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		philo[i].lastmeal = 0;
		philo[i].data = data;
		philo[i].id = i;
		philo[i].fork_left = i;
		philo[i].fork_right = (i + 1) % data->n_philo;
		philo[i].eat_count = 0;
		i++;
	}
}

int	init_data(int ac, char **av, t_data *data)
{
	data->n_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->dead = 0;
	data->satisfied = 0;
	if (ac == 6)
	{
		data->must_eat_count = ft_atoi(av[5]);
		if (data->must_eat_count <= 0)
			return (0);
	}
	else
		data->must_eat_count = -1;
	if (data->n_philo < 1 || data->time_to_die < 60 || data->time_to_sleep < 60
		|| data->time_to_eat < 60)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 6 && ac != 5)
		return (error(1));
	if (!check_arguments(av, ac))
		return (error(2));
	if (!init_data(ac, av, &data))
		return (error(2));
	init_mutex(&data);
	if (!philosophers(&data))
		return (error(3));
	return (0);
}
