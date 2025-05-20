/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:43:42 by mring             #+#    #+#             */
/*   Updated: 2025/05/20 17:50:17 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long time_now(void)
{
	struct timeval now;
	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

// exit strategies for uslep wrapper (death, timeout etc)