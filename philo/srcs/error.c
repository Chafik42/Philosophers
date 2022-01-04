/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:24:44 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/04 15:42:27 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	error(int error)
{
	if (error == 1)
		printf("Wrong number of Arguments, END\n");
	if (error == 2)
		printf("Wrong Arguments, END\n");
	return (0);
}
