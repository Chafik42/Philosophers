/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:08:53 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/11 16:45:46 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

void	print_action(t_philos *philo, t_rules *rules, int philo_id, char *str)
{
	pthread_mutex_lock(&(philo->action_printing));
	printf("%lld ", timestamp() - rules->time_start);
	printf("%d", philo_id);
	printf("%s", str);
	pthread_mutex_unlock(&(philo->action_printing));
}
