/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:27:12 by cmarouf           #+#    #+#             */
/*   Updated: 2022/01/04 14:37:18 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	thread1(void)
{
	printf("Je suis le premier thread et je vit tout seul !");
}

void	thread2(void)
{
	printf("Hahahaha etant le deuxieme thread j'emmerde le premier !");
}

void	thread3(void)
{
	printf("Les autres ne sont que baliverne");
}

int	main(void)
{
	pthread_t t1;
	pthread_t t2;
	//pthread_t t3;

	pthread_create(&t1, NULL, &thread1, NULL);
	pthread_create(&t2, NULL, &thread2, NULL);
	//pthread_create(&t3, NULL, &thread3, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}	
