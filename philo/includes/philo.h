/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:21:13 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/16 16:55:09 by cmarouf          ###   ########.fr       */
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
	struct s_data	*data;
}					t_philos;

typedef struct s_data
{
	int				n_philo;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				must_eat_count;
	long long		time_start;
	int				dead;
	int				satisfied;
	pthread_mutex_t	*forks;
	pthread_mutex_t	action_printing;
	pthread_mutex_t	eating;
}				t_data;

/* ERROR MANAGEMENT */
int			error(int error);
int			check_arguments(char **av, int ac);

/* UTILS FUNCTIONS */
int			ft_atoi(const char *nptr);
void		print_action(t_data *data, int philo_id, char *str);
long long	timestamp(void);

/* MAIN FUNCTIONS */
int			philosophers(t_data *data);
void		init_philo(t_philos *philo, t_data *data);
void		init_mutex(t_data *data);
void		exit_thread(t_philos *philo, t_data *data);
int			start_threads(t_philos *philo, t_data *data, int i);
int			check_end(t_philos *philo, t_data *data, int i);
void		*init(void *data);
void		sleep_andcheck(long long time, t_data *data);

#endif
