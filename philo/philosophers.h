/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:18:16 by mring             #+#    #+#             */
/*   Updated: 2025/05/12 18:00:05 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>  // mutex, threads
# include <stdbool.h>  // booleans for true/false functions
# include <stdio.h>    // stdin, stdout, stderror, printf, etc.
# include <stdlib.h>   // malloc, free
# include <sys/time.h> // gettimeofday
# include <unistd.h>   // write, usleep
// # include <limits.h> // INT_MAX

typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					fork_id;
}						t_fork;

typedef struct s_table
{
	int sleeptime;      // time to sleep
	int deathtime;      // time until death without food
	int eattime;        // time to eaten
	int meals;          // amount of meals everyone needs
	int philo_nbr;      // amount of philos
	int start_sim;      // time stamp of sim start
	bool end_sim;       // full or dead philos trigger end
	bool threads_ready; // for synchronizing philos
}						t_table;

typedef struct s_philo	t_philo;
// make individal struct for the table
// else you pull memory for each philo for unnecessary variables
// like sleeptime, deathtime, meals, eattime,
// philo_nbr, start_sim, end_sim
// ./philo 10 410 200 200 [10]
struct					s_philo
{
	int id;            // philo individual id
	int meals_counter; // how many meals eaten?
	bool full;         // if its full
	int last_meal;     // time passed from last mean
	t_philo				*philos;
	t_fork				*left_fork;
	t_fork				*right_fork;
	pthread_t thread_id; // a philo is a thread
	t_table *table;      // table struct
	t_fork *forks;       // fork struct
};

void					error_exit(const char *error);
int						ft_atoi(char *s);
void					parse_input(int ac, char **av, t_philo *philo);
void					*safe_malloc(size_t bytes);
void					dinner_start(t_philo *philo);

#endif
