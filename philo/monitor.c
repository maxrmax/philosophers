/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:18:04 by mring             #+#    #+#             */
/*   Updated: 2025/05/26 22:18:15 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	philo_death(t_philo *philo)
{
	if (philo->table->deathtime > time_now() - philo->last_meal)
		return (false);
	return (true);
}

void	*monitor(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	// check if the simulation is still running
	while (!get_bool(&table->table_mtx, &table->end_sim))
	{
		i = -1;
		while (++i < table->philo_nbr)
		{
			if (philo_death(table->philos + i) && table->end_sim)
			{
				set_bool(&table->table_mtx, &table->end_sim, true);
				printf("Philosopher %d died\n", table->philos[i].id);
				return (NULL);
			}
		}
	}
	return (NULL);
}
