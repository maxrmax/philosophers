/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:17:54 by mring             #+#    #+#             */
/*   Updated: 2025/04/29 17:56:33 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void error_exit(const char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}

void	parse_input(int ac, char **av, philo *philo)
{
	if (ac == 5)
		philo->meals = 0;
	else
		philo->meals = ft_atoi(av[5]);
	philo->sleeptime = ft_atoi(av[4]); 
	philo->eattime = ft_atoi(av[3]);
	philo->deathtime = ft_atoi(av[2]);
	philo->philos = ft_atoi(av[1]);
	if (philo->deathtime < 60 || philo->eattime < 60 || philo->sleeptime < 60)
		error_exit("Use timestamps larger than 60ms");
	printf("philos: %d\n", philo->philos);
	printf("death: %d\n", philo->deathtime);
	printf("eat: %d\n", philo->eattime);
	printf("sleep: %d\n", philo->sleeptime);
	printf("meals: %d\n", philo->meals);
	// we checked the input to be correct, then assigned it to each value
	// the struct is initialized, if no meal amount was given,
	// it should run indefinetly or until a philo dies
}

void	data_init(philo *philo)
{
	philo->end_sim = false;
	
	;
}

int	main(int ac, char **av)
{
	philo	philo;

	if (ac == 5 || ac == 6)
	{
		parse_input(ac, av, &philo);
		data_init(&philo);
	}
	else
	{
		error_exit("Usage: ./philo number_of_philos time_to_die time_to_eat time_to_sleep [meal_amount]");
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