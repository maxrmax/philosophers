/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:22:26 by mring             #+#    #+#             */
/*   Updated: 2025/04/29 15:15:48 by mring            ###   ########.fr       */
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
