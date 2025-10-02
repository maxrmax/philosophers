/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:09:12 by mring             #+#    #+#             */
/*   Updated: 2025/10/03 18:55:57 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	single_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	write_philo_status("has taken a fork", philo);
	pthread_mutex_unlock(&philo->first_fork->fork);
	ph_usleep(philo->table->deathtime + 1, philo->table);
}

static void	eat(t_philo *philo)
{
	long	current_meals;

	if (philo->table->philo_nbr == 1)
	{
		single_philo_eat(philo);
		return ;
	}
	pthread_mutex_lock(&philo->first_fork->fork);
	write_philo_status("has taken the first fork", philo);
	pthread_mutex_lock(&philo->second_fork->fork);
	write_philo_status("has taken the second fork", philo);
	set_long(&philo->philo_mtx, &philo->last_meal, time_now());
	write_philo_status("is eating", philo);
	ph_usleep(philo->table->eattime, philo->table);
	current_meals = get_long(&philo->philo_mtx, &philo->meals_counter);
	set_long(&philo->philo_mtx, &philo->meals_counter, current_meals + 1);
	pthread_mutex_unlock(&philo->second_fork->fork);
	pthread_mutex_unlock(&philo->first_fork->fork);
}

static void	*dinner_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo);
	set_long(&philo->philo_mtx, &philo->last_meal, time_now());
	de_sync_philo(philo);
	while (!get_bool(&philo->table->table_mtx, &philo->table->end_sim))
	{
		if (get_bool(&philo->table->table_mtx, &philo->table->all_full))
			break ;
		eat(philo);
		write_philo_status("is sleeping", philo);
		ph_usleep(philo->table->sleeptime, philo->table);
		write_philo_status("is thinking", philo);
		if (philo->table->philo_nbr % 2 == 1)
			ph_usleep(philo->table->eattime, philo->table);
	}
	return (NULL);
}

void	dinner_start(t_table *table)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&table->table_mtx);
	while (++i < table->philo_nbr)
	{
		pthread_create(&table->philos[i].thread_id, NULL, dinner_sim,
			&table->philos[i]);
	}
	table->sim_start = time_now();
	table->threads_ready = true;
	pthread_mutex_unlock(&table->table_mtx);
	monitor(table);
	usleep(1000);
	while (--i >= 0)
		pthread_join(table->philos[i].thread_id, NULL);
}
