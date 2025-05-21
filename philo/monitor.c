/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:18:04 by mring             #+#    #+#             */
/*   Updated: 2025/05/21 16:08:36 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// static bool	philo_death(t_philo *philo)
// {
// 	if (philo->table->deathtime > time_now() - philo->last_meal)
// 		return (true); // 1
// 	return (false);    // 0
// }

// needs to check if a philo died,
void	*monitor(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	/* thought process:
	the monitor needs to check if the sim is finished
	-> when is the sim finished?
	when every philo ate [X] amount
	when a philo died
	-> what will i need for that?
	a loop for every thread
	check inside the loop if any philo died (sub) and if the sim is still going (sub?)
	*/
	// check how much was eaten by each philo
	// check if philo died≠
	//
	;
	printf("0\n");
	sleep(1);
	i = -1;
	printf("bool1: %d\n", get_bool(&table->table_mtx, &table->end_sim));
	while (get_bool(&table->table_mtx, &table->end_sim) && i++ < 5)
	{
		printf("1\n");
		// 	while (++i < table->philo_nbr)
		// 	{
		// 		if (philo_died(table->philos + i) && !sim_status(table))
		// 		{
		// 			// set sim_end true
		// 			// print death status
		// 			return (NULL);
		// 		}
		// 	}
		if (true)
		{
			printf("2\n");
			set_bool(&table->table_mtx, &table->end_sim, false);
			printf("bool2: %d\n", get_bool(&table->table_mtx, &table->end_sim));
		}
	}
	printf("3\n");
	return (NULL);
}
