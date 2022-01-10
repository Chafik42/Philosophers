/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:23:09 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/10 16:47:12 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

long long	timestamp(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec / 1000));
}

void	init_mutex(t_philos *philo, t_rules *rules)
{
	pthread_mutex_init(philo->&fork);
	pthread_mutex_init(rules->&action_printing);
	pthread_mutex_init(rules->&eating);
}

void	init_philo(t_philos *philo, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_philo)
	{
		philo[i].lastmeal = 0;
		philo[i].rules = rules;
		philo[i].id = i;
		i++;
	}
}

void	init_rules(int ac ,char **av, t_rules *rules)
{
	rules->n_philo = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_sleep = ft_atoi(av[3]);
	rules->time_to_eat = ft_atoi(av[4]);
	if (ac == 6)
		rules->must_eat_count = ft_atoi(av[5]);
	else
		rules->must_eat_count = 0;
}

int	main(int ac, char **av)
{
	t_rules *rules;

	rules = malloc(sizeof(rules));
	if (!rules)
		return (0);
	if (ac != 6 && ac != 5)
		return (error(1));
	if (!check_arguments(av, ac))
		return (error(2));
	init_rules(ac, av, rules);
	if (!philosophers(rules))
		return (error(2));
	return (0);
}
