/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:21:13 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/15 18:50:34 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philos
{
	int				fork_right;
	int				fork_left;
	int				id;
	long long		lastmeal;
	int				eat_count;
	pthread_t		t_id;
	struct s_rules *rules;
	pthread_mutex_t *forks;
	pthread_mutex_t action_printing;
	pthread_mutex_t eating;
}				t_philos;

typedef struct s_rules
{
	int	n_philo;
	int	time_to_die;
	int	time_to_sleep;
	int	time_to_eat;
	int	must_eat_count;
	long long	time_start;
	int	dead;
	int	satisfied;
	struct s_philos *philo;
}				t_rules;

/* ERROR MANAGEMENT */
int	error(int error);
int	check_arguments(char **av, int ac);

/* UTILS FUNCTIONS */
int	ft_atoi(const char *nptr);
void	print_action(t_philos *philo, t_rules *rules, int philo_id, char *str);
long long	timestamp(void);

/* MAIN FUNCTIONS */
int		philosophers(t_rules *rules);
void	init_philo(t_philos *philo, t_rules *rules);
void	init_mutex(t_philos *philo, t_rules *rules);
void	exit_thread(t_philos *philo, t_rules *rules);
int		start_threads(t_philos *philo, t_rules *rules);
void	check_end(t_philos *philo, t_rules *rules);
void	*init(void *data);
void	sleep_andcheck(long long time, t_rules *rules);

#endif
