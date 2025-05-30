/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:49:52 by mring             #+#    #+#             */
/*   Updated: 2025/05/30 01:03:01 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	assign_forks(t_table *table, t_fork *forks, int pos)
{
	if (table->philos[pos].id % 2 == 0)
	{
		table->philos[pos].first_fork = &forks[pos];
		table->philos[pos].second_fork = &forks[(pos + 1) % table->philo_nbr];
	}
	else
	{
		table->philos[pos].first_fork = &forks[(pos + 1) % table->philo_nbr];
		table->philos[pos].second_fork = &forks[pos];
	}
}

static void	philo_init(t_table *table, t_fork *forks)
{
	int	i;

	i = -1;
	while (++i < table->philo_nbr)
	{
		table->philos[i].id = i + 1;
		table->philos[i].last_meal = time_now();
		table->philos[i].meals_counter = 0;
		table->philos[i].table = table;
		assign_forks(table, forks, i);
	}
}

void	data_init(t_table *table)
{
	int	i;

	table->threads_ready = false;
	table->end_sim = false;
	table->full_counter = 0;
	table->all_full = false;
	table->philos = safe_malloc(sizeof(t_philo) * table->philo_nbr);
	table->forks = safe_malloc(sizeof(t_fork) * table->philo_nbr);
	i = -1;
	while (++i < table->philo_nbr)
	{
		pthread_mutex_init(&table->forks[i].fork, NULL);
		// good for debugging apparently
		// TODO: check if obsolete
		table->forks[i].fork_id = i;
	}
	philo_init(table, table->forks);
}
