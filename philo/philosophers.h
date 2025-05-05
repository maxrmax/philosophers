/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:18:16 by mring             #+#    #+#             */
/*   Updated: 2025/05/05 15:36:44 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct philo
{
	int				eattime;
	int				sleeptime;
	int				deathtime;
	int				*philos;
	int				philo_nbr;
	int				meals;
	int				id;
	int				meals_counter;
	int				last_meal;
	bool			full;
	pthread_t		p_id;
	pthread_mutex_t	fork;
	int				fork_id;
	int				start_sim;
	bool			end_sim;

}					philo;

void				error_exit(const char *error);
int					ft_atoi(char *s);
void				parse_input(int ac, char **av, philo *philo);
void				*safe_malloc(size_t bytes);

#endif
