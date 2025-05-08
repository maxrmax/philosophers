/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:22:26 by mring             #+#    #+#             */
/*   Updated: 2025/05/08 14:52:58 by mring            ###   ########.fr       */
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

void	parse_input(int ac, char **av, philo *philo)
{
	if (ac == 5)
		philo->meals = 0;
	else
		philo->meals = ft_atoi(av[5]);
	philo->sleeptime = ft_atoi(av[4]);
	philo->eattime = ft_atoi(av[3]);
	philo->deathtime = ft_atoi(av[2]);
	philo->philo_nbr = ft_atoi(av[1]);
	if (philo->deathtime < 60 || philo->eattime < 60 || philo->sleeptime < 60)
		error_exit("Use timestamps larger than 60ms");
	printf("philos: %d\n", philo->philo_nbr);
	printf("death: %d\n", philo->deathtime);
	printf("eat: %d\n", philo->eattime);
	printf("sleep: %d\n", philo->sleeptime);
	printf("meals: %d\n", philo->meals);
	// we checked the input to be correct, then assigned it to each value
	// the struct is initialized, if no meal amount was given,
	// it should run indefinetly or until a philo dies
}
