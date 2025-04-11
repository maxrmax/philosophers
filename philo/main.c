/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:17:54 by mring             #+#    #+#             */
/*   Updated: 2025/04/11 15:47:42 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	parse_pre_init(char **av)
{
	int	test;

	test = ft_atoi(av[2]);
	if (test == -1)
	{
		printf("atoi parsing\n");
		exit(1);
	}
	printf("%d\n", test);
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		parse_pre_init(av);
	}
	else
	{
		printf("Usage: \
	%s number_of_philos time_to_die time_to_eat time_to_sleep [meal_amount]\n",
				av[0]);
		return (1);
	}
	// parsing
	// init philos
	// ^ or standalone: init fork and threads
	// philo loop
}

// set"ter" get"ter" functions to set/get mutex status
// write lock is a mutex

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock