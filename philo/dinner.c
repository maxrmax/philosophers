/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:09:12 by mring             #+#    #+#             */
/*   Updated: 2025/05/12 17:46:48 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*dinner_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	// wait_all_threads(philo->table); // TODO
	return (NULL);
}

void	dinner_start(t_philo *philo)
{
	int	i;

	i = -1;
	if (philo->table->meals == 0)
		return ;
	else if (philo->table->philo_nbr)
		;
	else
		while (++i < philo->table->philo_nbr)
		{
			pthread_create(&philo->philos[i].thread_id, NULL, dinner_sim,
				&philo->philos[i]);
		}
	// now all threads are made
	// set bool true for all ready
}
