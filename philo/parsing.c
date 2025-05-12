/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:22:26 by mring             #+#    #+#             */
/*   Updated: 2025/05/09 12:21:34 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *s)
{
	int	result;
	int	sign;
	int	i;

	if (!s)
		error_exit("No String");
	i = 0;
	result = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || (s[i] == 32))
		i++;
	if (s[i] == '+' && s[i + 1] != '-')
		i++;
	if (s[i] == '-')
		error_exit("Only positive numbers");
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (result > (2147483647 - (s[i] - '0')) / 10)
			error_exit("Only positive numbers within INT range");
		result = (result * 10) + s[i++] - '0';
	}
	if (!(s[i] >= '0' && s[i] <= '9') && !(s[i] == '\0'))
		error_exit("Only digits are allowed");
	return (result * sign);
}

void	parse_input(int ac, char **av, t_philo *philo)
{
	if (ac == 5)
		philo->table->meals = 0;
	else
		philo->table->meals = ft_atoi(av[5]);
	philo->table->sleeptime = ft_atoi(av[4]);
	philo->table->eattime = ft_atoi(av[3]);
	philo->table->deathtime = ft_atoi(av[2]);
	philo->table->philo_nbr = ft_atoi(av[1]);
	if (philo->table->deathtime < 60 || philo->table->eattime < 60
		|| philo->table->sleeptime < 60)
		error_exit("Use timestamps larger than 60ms");
	printf("philos: %d\n", philo->table->philo_nbr);
	printf("death: %d\n", philo->table->deathtime);
	printf("eat: %d\n", philo->table->eattime);
	printf("sleep: %d\n", philo->table->sleeptime);
	printf("meals: %d\n", philo->table->meals);
	// we checked the input to be correct, then assigned it to each value
	// the struct is initialized, if no meal amount was given,
	// it should run indefinetly or until a philo dies
}
