/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:17:54 by mring             #+#    #+#             */
/*   Updated: 2025/05/11 16:31:32 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error_exit(const char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}

/* already init by parsing
	philo->meals		= ft_atoi(av[5]);
	philo->sleeptime	= ft_atoi(av[4]);
	philo->eattime		= ft_atoi(av[3]);
	philo->deathtime	= ft_atoi(av[2]);
	philo->philo_nbr	= ft_atoi(av[1]);
*/

// one time init at start:
// end_sim
// id
// forks,
// threads,
void	data_init(t_philo *philo)
{
	philo->table->end_sim = false;
	philo->table->end_sim = false;
	philo->philos = safe_malloc(philo->table->philo_nbr);
	error_exit("Success");
}

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac == 5 || ac == 6)
	{
		parse_input(ac, av, &philo);
		data_init(&philo);
		// table
		// cleanup
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