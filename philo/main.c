/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:17:54 by mring             #+#    #+#             */
/*   Updated: 2025/05/12 18:03:05 by mring            ###   ########.fr       */
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

static void	assign_forks(t_philo *philo, t_fork *forks, int pos)
{
	int	philo_nbr;

	// *philo_pos = philo_id -1
	// left_fork = (philo_pos + 1) % philo_nbr
	// (4 + 1) % 5 = 0
	philo_nbr = philo->table->philo_nbr;
	// potential deadlock
	philo->left_fork = &forks[pos];
	philo->right_fork = &forks[(pos + 1) % philo_nbr];
	if (philo->id % 2 == 0)
	{
		philo->right_fork = &forks[pos];
		philo->left_fork = &forks[(pos + 1) % philo_nbr];
	}
}

static void	philo_init(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->table->philo_nbr)
	{
		philo++;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		assign_forks(philo, philo->forks, i);
	}
}

// one time init at start:
// end_sim
// id
// forks,
// threads,
void	data_init(t_philo *philo)
{
	int	i;

	i = -1;
	philo->table->end_sim = false;
	philo->table->threads_ready = false;
	philo->philos = safe_malloc(sizeof(t_philo) * philo->table->philo_nbr);
	philo->forks = safe_malloc(sizeof(t_fork) * philo->table->philo_nbr);
	while (++i < philo->table->philo_nbr)
	{
		pthread_mutex_init(&philo->forks[i].fork, NULL);
		philo->forks[i].fork_id = i; // good for debugging
	}
	philo_init(philo);
	error_exit("Success");
}

int	main(int ac, char **av)
{
	t_philo	philo;
	t_table	table;

	philo.table = &table;
	if (ac == 5 || ac == 6)
	{
		parse_input(ac, av, &philo);
		// data_init(&philo);
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