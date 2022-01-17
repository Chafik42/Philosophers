/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:51:09 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/17 17:51:10 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	philo_eat(t_philos *philo, t_data *data)
{
	int	temp_fork;

	if (philo->fork_left > philo->fork_right)
	{
		temp_fork = philo->fork_right;
		philo->fork_right = philo->fork_left;
		philo->fork_left = temp_fork;
	}
	pthread_mutex_lock(&(data->forks[philo->fork_left]));
	print_action(data, philo->id, " has taken a fork\n");
	pthread_mutex_lock(&(data->forks[philo->fork_right]));
	print_action(data, philo->id, " has taken a fork\n");
	pthread_mutex_lock(&(data->eating));
	print_action(data, philo->id, " is eating\n");
	philo->lastmeal = timestamp();
	pthread_mutex_unlock(&(data->eating));
	sleep_andcheck(data->time_to_eat, data);
	philo->eat_count++;
	pthread_mutex_unlock(&(data->forks[philo->fork_left]));
	pthread_mutex_unlock(&(data->forks[philo->fork_right]));
}

void	*init(void *void_data)
{
	t_philos	*philo;
	t_data		*data;

	philo = (t_philos *)void_data;
	data = philo->data;
	while (!data->dead)
	{
		philo_eat(philo, data);
		if (data->satisfied)
			return (NULL);
		print_action(data, philo->id, " is sleeping\n");
		sleep_andcheck(data->time_to_sleep, data);
		print_action(data, philo->id, " is thinking\n");
	}
	return (NULL);
}

int	philosophers(t_data *data)
{
	t_philos	*philo;

	philo = malloc(sizeof(t_philos) * (data->n_philo));
	if (!philo)
		return (0);
	init_philo(philo, data);
	data->time_start = timestamp();
	if (!start_threads(philo, data, 0))
		return (0);
	data->satisfied = check_end(philo, data, 0);
	if (!exit_thread(philo, data))
		return (0);
	free(philo->data->forks);
	free(philo);
	return (1);
}
