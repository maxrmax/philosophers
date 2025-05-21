/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:18:16 by mring             #+#    #+#             */
/*   Updated: 2025/05/21 16:03:03 by mring            ###   ########.fr       */
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

typedef struct s_table	t_table;

typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					fork_id;
}						t_fork;

// philosophers are egoistic
// they only know about themself, how many eals they have eaten
// if they are full, last_meal time
// their forks right and left of them
// and every philo has their own ID and THREAD_ID
typedef struct s_philo
{
	int id;            // philo individual id
	int meals_counter; // how many meals eaten?
	bool full;         // if its full
	int last_meal;     // time passed from last mean
	t_fork				*first_fork;
	t_fork				*second_fork;
	t_table				*table;
	pthread_t thread_id; // a philo is a thread
	pthread_mutex_t		philo_mtx;
}						t_philo;

// table is the master struct.
// the table knows it all.
// the table contains all forks
// all philos sit on the table
struct					s_table
{
	int sleeptime;      // time to sleep
	int deathtime;      // time until death without food
	int eattime;        // time to eaten
	int meals;          // amount of meals everyone needs
	int philo_nbr;      // amount of philos
	bool threads_ready; // for synchronizing philos
	bool end_sim;       // full or dead philos trigger end
	long sim_start;     // time stamp of sim start
	pthread_mutex_t		table_mtx;
	pthread_t			monitor;
	t_philo				*philos;
	t_fork				*forks;
};

void					error_exit(const char *error);
int						ft_atoi(char *s);
void					parse_input(int ac, char **av, t_table *table);
void					*safe_malloc(size_t bytes);
void					data_init(t_table *table);
void					dinner_start(t_table *table);
void					philo_debug(t_table *table);
long					time_now(void);
void					cleanup(t_table *table);
void					wait_all_threads(t_philo *philo);
void					*monitor(void *data);
void					set_bool(pthread_mutex_t *mutex, bool *dest,
							bool value);
bool					get_bool(pthread_mutex_t *mutex, bool *value);
void					set_long(pthread_mutex_t *mutex, long *dest,
							long value);
long					get_long(pthread_mutex_t *mutex, long *value);

#endif
