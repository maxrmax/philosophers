/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:18:04 by mring             #+#    #+#             */
/*   Updated: 2025/06/02 18:08:58 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	philo_death(t_philo *philo)
{
	if (philo->table->deathtime <= time_now() - get_long(&philo->philo_mtx,
			&philo->last_meal))
	{
		printf("Philosopher %d died at %-6ld\n", philo->id, time_now()
			- philo->table->sim_start);
		set_bool(&philo->table->table_mtx, &philo->table->end_sim, true);
		return (true);
	}
	return (false);
}

static bool	philo_full(t_philo *philo)
{
	if (philo->meals_counter >= philo->table->meals)
		return (true);
	return (false);
}

void	*monitor(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	while (!get_bool(&table->table_mtx, &table->end_sim))
	{
		i = -1;
		table->full_counter = 0;
		while (++i < table->philo_nbr)
		{
			if (philo_death(table->philos + i))
				return (NULL);
			if (philo_full(table->philos + i) && !table->end_sim)
				table->full_counter += 1;
			if (table->full_counter >= table->philo_nbr && table->meals > 0)
			{
				set_bool(&table->table_mtx, &table->all_full, true);
				set_bool(&table->table_mtx, &table->end_sim, true);
			}
		}
		usleep(1000);
	}
	return (NULL);
}
