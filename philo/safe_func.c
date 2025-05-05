/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:31:26 by mring             #+#    #+#             */
/*   Updated: 2025/05/05 15:36:41 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// wrapper for safe malloc usage
void	*safe_malloc(size_t bytes)
{
	void	*result;

	result = malloc(bytes);
	if (result == NULL)
		error_exit("malloc failure");
	return (result);
}

// wrapper for safe mutex usage
// init, destroy, lock, unlock
// void safe_mutex_handler(t_mtx *mutex, enum opcode)
// {

// }