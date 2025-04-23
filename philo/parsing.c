/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:22:26 by mring             #+#    #+#             */
/*   Updated: 2025/04/22 16:11:21 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_atoi_error(void)
{
	printf("Error: Only positive whole numbers allowed (e.g. 123)\n");
	exit(1);
}

int	ft_atoi(char *s)
{
	int	result;
	int	sign;
	int	i;

	if (!s)
		ft_atoi_error();
	i = 0;
	result = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || (s[i] == 32))
		i++;
	if (s[i] == '+' && s[i + 1] != '-')
		i++;
	if (s[i] == '-')
		ft_atoi_error();
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (result > (2147483647 - (s[i] - '0')) / 10)
			ft_atoi_error();
		result = (result * 10) + s[i++] - '0';
	}
	if (!(s[i] >= '0' && s[i] <= '9') && !(s[i] == '\0'))
		ft_atoi_error();
	return (result * sign);
}
// 2147483647
// bool	int_range(char **tokens)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	while (tokens[i])
// 	{
// 		len = ft_strlen(tokens[i]);
// 		if (len > 10 && tokens[i][0] != '-')
// 			return (1);
// 		if (len == 10 || (len == 11 && tokens[i][0] == '-'))
// 		{
// 			if (tokens[i][0] == '-' && (ft_strncmp(tokens[i], "-2147483648",
// 						11) > 0))
// 				return (1);
// 			else if (ft_strncmp(tokens[i], "2147483647", 10) > 0)
// 				return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }