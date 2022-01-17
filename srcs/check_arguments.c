/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:40:44 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/04 15:50:32 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_arguments(char **av, int ac)
{
	if (!is_num(av[1]) || !is_num(av[2]) || !is_num(av[3]) || !is_num(av[4]))
		return (0);
	if (ac == 6)
	{
		if (!is_num(av[5]))
			return (0);
	}
	return (1);
}
