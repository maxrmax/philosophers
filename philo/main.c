/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:17:54 by mring             #+#    #+#             */
/*   Updated: 2025/05/13 17:02:48 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error_exit(const char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}

static void	assign_forks(t_philo *philos, t_fork *forks, int pos)
{
	int	philo_nbr;

	philo_nbr = philos->table->philo_nbr;
	philos->left_fork = &forks[pos];
	philos->right_fork = &forks[(pos + 1) % philo_nbr];
	if (philos->id % 2 == 0)
	{
		philos->right_fork = &forks[pos];
		philos->left_fork = &forks[(pos + 1) % philo_nbr];
	}
}

static void	philo_init(t_philo *philos, t_fork *forks)
{
	int	i;

	i = -1;
	while (++i < philos->table->philo_nbr)
	{
		philos[i].id = i + 1;
		philos[i].full = false;
		philos[i].meals_counter = 0;
		philos[i].table = philos->table;
		assign_forks(&philos[i], forks, i);
	}
}

void	data_init(t_philo *philo)
{
	int	i;

	philo->table->end_sim = false;
	philo->table->threads_ready = false;
	philo->table->philos = safe_malloc(sizeof(t_philo)
			* philo->table->philo_nbr);
	philo->table->forks = safe_malloc(sizeof(t_fork) * philo->table->philo_nbr);
	i = -1;
	while (++i < philo->table->philo_nbr)
	{
		pthread_mutex_init(&philo->table->forks[i].fork, NULL);
		philo->table->forks[i].fork_id = i; // good for debugging apparently
	}
	philo_init(philo->table->philos, philo->table->forks);
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
		data_init(&philo);
		// table
		// cleanup
	}
	else
	{
		error_exit("Usage: ./philo number_of_philos time_to_die time_to_eat time_to_sleep [meal_amount]");
	}
}
