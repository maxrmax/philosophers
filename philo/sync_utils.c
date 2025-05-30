/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:05:00 by mring             #+#    #+#             */
/*   Updated: 2025/05/30 01:48:23 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_all_threads(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->table->table_mtx);
		if (philo->table->threads_ready)
		{
			pthread_mutex_unlock(&philo->table->table_mtx);
			break ;
		}
		pthread_mutex_unlock(&philo->table->table_mtx);
		usleep(1000);
	}
}

// TODO: check this - can it be adjusted?
void	de_sync_philo(t_philo *philo)
{
	write_philo_status("is thinking", philo);
	// Even philosophers should delay to prevent deadlock
	if (philo->id % 2 == 0)
		ph_usleep(philo->table->eattime / 3, philo->table);
	// // if its an even philo start thinking
	// if (philo->id % 2 == 0)
	// 	write_philo_status("is thinking", philo);
	// // if its an odd philo think (sleep) half the eat time
	// else
	// {
	// 	write_philo_status("is thinking", philo);
	// 	ph_usleep(philo->table->eattime / 2, philo->table);
	// }
}
