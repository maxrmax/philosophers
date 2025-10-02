/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:17:54 by mring             #+#    #+#             */
/*   Updated: 2025/10/03 18:02:10 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	cleanup(t_table *table)
{
	int	i;

	i = table->philo_nbr;
	while (--i >= 0)
	{
		pthread_mutex_destroy(&table->forks[i].fork);
		pthread_mutex_destroy(&table->philos[i].philo_mtx);
	}
	pthread_mutex_destroy(&table->table_mtx);
	free(table->philos);
	free(table->forks);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		parse_input(ac, av, &table);
		data_init(&table);
		dinner_start(&table);
		cleanup(&table);
	}
	else
		error_exit("Usage: ./philo number_of_philos \
time_to_die time_to_eat time_to_sleep [meal_amount]");
}
