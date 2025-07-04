/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:05:00 by mring             #+#    #+#             */
/*   Updated: 2025/07/04 13:40:25 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	de_sync_philo(t_philo *philo)
{
	write_philo_status("is thinking", philo);
	if (philo->id % 2 == 0)
		ph_usleep(philo->table->eattime / 2, philo->table);
}
