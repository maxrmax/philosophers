/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:18:04 by mring             #+#    #+#             */
/*   Updated: 2025/10/03 18:26:32 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	philo_death(t_philo *philo)
{
	if (philo->table->deathtime <= time_now() - get_long(&philo->philo_mtx,
			&philo->last_meal))
	{
		pthread_mutex_lock(&philo->table->table_mtx);
		if (!philo->table->end_sim)
		{
			printf("%-6ld %d\033[1;31m died\033[0m\n", time_now()
				- philo->table->sim_start, philo->id);
			philo->table->end_sim = true;
		}
		pthread_mutex_unlock(&philo->table->table_mtx);
		return (true);
	}
	return (false);
}

static bool	philo_full(t_philo *philo)
{
	if (get_long(&philo->philo_mtx,
			&philo->meals_counter) >= philo->table->meals)
		return (true);
	return (false);
}

void	*monitor(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	wait_all_threads((t_philo *)table->philos);
	while (!get_bool(&table->table_mtx, &table->end_sim))
	{
		i = -1;
		table->full_counter = 0;
		while (++i < table->philo_nbr && !get_bool(&table->table_mtx,
				&table->end_sim))
		{
			if (philo_death(table->philos + i))
				return (NULL);
			if (philo_full(table->philos + i))
				table->full_counter += 1;
		}
		if (table->full_counter >= table->philo_nbr && table->meals > 0)
		{
			set_bool(&table->table_mtx, &table->end_sim, true);
			set_bool(&table->table_mtx, &table->all_full, true);
		}
		usleep(200);
	}
	return (NULL);
}
