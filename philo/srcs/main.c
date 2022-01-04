/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:23:09 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/04 16:39:11 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <philo.h>



void	init_variables(int ac ,char **av, t_vphilo *philo)
{
	philo->n_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_sleep = ft_atoi(av[3]);
	philo->time_to_eat = ft_atoi(av[4]);
	if (ac == 6)
		philo->must_eat_count = ft_atoi(av[5]);
	else
		philo->must_eat_count = 0;
}

int	main(int ac, char **av)
{
	t_vphilo *philo;

	philo = malloc(sizeof(t_vphilo));
	if (!philo)
		return (0);
	if (ac != 6 && ac != 5)
		return (error(1));
	if (!check_arguments(av, ac))
		return (error(2));
	init_variables(ac, av, philo);
	return (0);
}
