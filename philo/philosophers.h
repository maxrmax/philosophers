/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:18:16 by mring             #+#    #+#             */
/*   Updated: 2025/04/15 14:18:45 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>

typedef struct philo
{
	int	eattime;
	int	sleeptime;
	int	deathtime;
	int	philos;
	int	meals;
}		philo;

int		ft_atoi(char *s);
void	parse_pre_init(int ac, char **av, philo *philo);

#endif
