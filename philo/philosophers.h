/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:18:16 by mring             #+#    #+#             */
/*   Updated: 2025/04/29 15:35:00 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>

typedef struct philo
{
	int	eattime;
	int	sleeptime;
	int	deathtime;
	int	philos;
	int	meals;
	int id;
	int	meals_counter;
	int last_meal;
	bool full;
	pthread_t id;
	pthread_mutex_t fork;
	int fork_id;
	int start_sim;
	bool end_sim;

}		philo;

void	error_exit(const char *error);
int		ft_atoi(char *s);
void	parse_input(int ac, char **av, philo *philo);

#endif
