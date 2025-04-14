/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:17:54 by mring             #+#    #+#             */
/*   Updated: 2025/04/14 17:02:07 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	parse_pre_init(int ac, char **av, philo *philo)
{
	if (ac == 5)
		philo->meals = 0;
	while (--ac >= 1)
	{
		if (ft_atoi(av[ac]) == -1)
		{
			printf("Only numbers are allowed\n");
			exit(1);
		}
		if (ac == 5)
			philo->meals = ft_atoi(av[5]);
		else if (ac == 4)
			philo->sleeptime = ft_atoi(av[4]);
		else if (ac == 3)
			philo->eattime = ft_atoi(av[3]);
		else if (ac == 2)
			philo->deathtime = ft_atoi(av[2]);
		else if (ac == 1)
			philo->philos = ft_atoi(av[1]);
	}
	printf("philos: %d\n", philo->philos);
	printf("death: %d\n", philo->deathtime);
	printf("eat: %d\n", philo->eattime);
	printf("sleep: %d\n", philo->sleeptime);
	printf("meals: %d\n", philo->meals);
	// we checked the input to be correct, then assigned it to each value
	// the struct is initialized, if no meal amount was given,
	// it should run indefinetly or until a philo dies
}

void	init_philos(void)
{
	// init philos, forks, threads.
}

int	main(int ac, char **av)
{
	philo	philo;

	if (ac == 5 || ac == 6)
	{
		parse_pre_init(ac, av, &philo);
		init_philos();
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