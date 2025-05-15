/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:09:12 by mring             #+#    #+#             */
/*   Updated: 2025/05/15 14:43:22 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	wait_all_threads(t_table *table)
{
	(void)table;
}

// do i need the full table data + every philo data here?
void	*dinner_sim(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	wait_all_threads(table); // TODO
	return (NULL);
}

void	dinner_start(t_table *table)
{
	int	i;

	i = -1;
	if (table->philo_nbr)
		;
	else
		while (++i < table->philo_nbr) // create thread for each philo
		{
			// need a condition to make them all wait after creating.
			// do i need to pass the whole table (everything) or just a single philo?
			pthread_create(&table->philos[i].thread_id, NULL, dinner_sim,
				&table);
			// detach after automatic cleanup after they close/end (unless they run infinite)
			pthread_detach(table->philos[i].thread_id);
		}
	// now all threads are made
	// set bool true for all ready
}
