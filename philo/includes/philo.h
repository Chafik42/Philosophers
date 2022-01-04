/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:21:13 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/04 16:31:54 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_vphilo
{
	int	n_philo;
	int	time_to_die;
	int	time_to_sleep;
	int	time_to_eat;
	int	must_eat_count;
}				t_vphilo;

/* ERROR MANAGEMENT */
int	error(int error);
int	check_arguments(char **av, int ac);

/* UTILS FONCTIONS */
int	ft_atoi(const char *nptr);

#endif
