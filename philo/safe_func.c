/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:31:26 by mring             #+#    #+#             */
/*   Updated: 2025/05/07 17:27:19 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
Unperformant,
	nutz die normalen pthread funktionen (lock unlock join detached etc)
weil 200 philo sterben einfach wegen milisekunden
*/

// wrapper for safe malloc usage
void	*safe_malloc(size_t bytes)
{
	void	*result;

	result = malloc(bytes);
	if (result == NULL)
		error_exit("malloc failure");
	return (result);
}

static void	handle_mutex_error(int status, t_opcode opcode)
{
	if (status = 0)
		return ;
	if (EINVAL == status && (lock == opcode || unlock == opcode))
		error_exit("The value specified by mutex is invalid.");
	else if (EINVAL == status && init == opcode)
		error_exit("The value specified by attr is invalid.");
	else if (EDEADLK == status)
		error_exit("A dead lock would occur if the thread blocked waiting for mutex..");
	else if (EPERM == status)
		error_exit("The current thread does not hold a lock on mutex.");
	else if (ENOMEM == status)
		error_exit("The process cannot allocate enough memory to create another mutex.");
	else if (EBUSY == status)
		error_exit("The value specified by attr is invalid.");
}

// wrapper for safe mutex usage
// init, destroy, lock, unlock
void	safe_mutex_handler(t_mtx *mutex, enum opcode)
{
	if (lock == opcode)
		handle_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (unlock == opcode)
		handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (init == opcode)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (destroy == opcode)
		handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
		error_exit("Wrong opcode for mutex handle");
}

static void	handle_thread_error(int status, t_opcode opcode)
{
	if (status = 0)
		return ;
	if (EAGAIN == status)
		error_exit("No resources to create another thread.");
	else if (EPERM == status)
		error_exit("The caller does not have appropiate permission\n.");
	else if (EINVAL == status && CREATE == opcode)
		error_exit("The value by attr is invalid.");
	else if (EINVAL == status && (join == opcode || detach == opcode))
		error_exit("The value by thread is not joinable.\n.");
	else if (ESRCH == status)
		error_exit("No thread could be found corresponding to that"
					"specified by the given thread ID, thread.");
	else if (EDEADLK == status)
		error_exit("A deadlock was detected or the value of"
					"thread specifies the calling thread.");
}

// wrapper for safe mutex usage
// init, destroy, lock, unlock
void	safe_thread_handler(pthread_t *thread, void *(*foo)(void *), void *data,
		t_opcode opcode)
{
	if (create == opcode)
		handle_thread_error(pthread_thread_ceate(thread, NULL), opcode);
	else if (join == opcode)
		handle_thread_error(pthread_thread_join(*thread, NULL), opcode);
	else if (detach == opcode)
		handle_thread_error(pthread_thread_detach(*thread), opcode);
	else
		error_exit("Wrong opcode for thread_handle: <create> <join> <detach>");
}
