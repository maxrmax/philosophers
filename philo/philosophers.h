/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:18:16 by mring             #+#    #+#             */
/*   Updated: 2025/06/02 18:11:17 by mring            ###   ########.fr       */
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
	// philo individual id
	int					id;
	// how many meals eaten?
	int					meals_counter;
	// time passed from last mean
	long				last_meal;
	t_fork				*first_fork;
	t_fork				*second_fork;
	t_table				*table;
	// thread_id per philo[i]
	pthread_t			thread_id;
	pthread_mutex_t		philo_mtx;
}						t_philo;

// table is master
// table knows all forks
// table tolerates philos
// table knows all
// table sees all
// all hail table
struct					s_table
{
	// time to sleep
	int					sleeptime;
	// time until death without food
	int					deathtime;
	// time to eaten
	int					eattime;
	// amount of meals everyone needs
	int					meals;
	//  if all philos are full
	int					full_counter;
	bool				all_full;
	// amount of philos
	int					philo_nbr;
	// for synchronizing philos
	bool				threads_ready;
	// time stamp of sim start
	long				sim_start;
	// full or dead philos trigger end
	bool				end_sim;
	pthread_mutex_t		table_mtx;
	pthread_t			monitor;
	t_philo				*philos;
	t_fork				*forks;
};

// parsing
int						ft_atoi(char *s);
void					parse_input(int ac, char **av, t_table *table);

void					data_init(t_table *table);

// sync utils
void					de_sync_philo(t_philo *philo);
void					wait_all_threads(t_philo *philo);

// dinner logic
void					dinner_start(t_table *table);
void					*monitor(void *data);
void					write_philo_status(char *msg, t_philo *philo);

// clean exit
void					cleanup(t_table *table);
void					error_exit(const char *error);

// utility
void					*safe_malloc(size_t bytes);
long					time_now(void);
void					set_bool(pthread_mutex_t *mutex, bool *dest,
							bool value);
bool					get_bool(pthread_mutex_t *mutex, bool *value);
void					set_long(pthread_mutex_t *mutex, long *dest,
							long value);
long					get_long(pthread_mutex_t *mutex, long *value);
void					ph_usleep(long time, t_table *table);

#endif
