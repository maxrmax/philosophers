/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:09:12 by mring             #+#    #+#             */
/*   Updated: 2025/05/13 16:13:11 by mring            ###   ########.fr       */
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

void	dinner_start(t_philo *philos, t_fork *forks)
{
	int	i;

	i = -1;
	if (philos->table->meals == 0)
		return ;
	else if (philos->table->philo_nbr)
		;
	else
		while (++i < philos->table->philo_nbr)
			pthread_create(&philos[i].thread_id, NULL, dinner_sim, &philos[i]);
	// now all threads are made
	// set bool true for all ready
}
