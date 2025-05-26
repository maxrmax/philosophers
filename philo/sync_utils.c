/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:05:00 by mring             #+#    #+#             */
/*   Updated: 2025/05/26 21:25:26 by mring            ###   ########.fr       */
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

void	de_sync_philo(t_philo *philo)
{
	if (philo->id % 2 == 0)
		write_philo_status("is thinking", philo);
	else
	{
		write_philo_status("is thinking", philo);
		ph_usleep(philo->table->eattime / 2, philo->table);
	}
}
