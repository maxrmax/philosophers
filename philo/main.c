/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:17:54 by mring             #+#    #+#             */
/*   Updated: 2025/05/21 13:31:28 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		parse_input(ac, av, &table);
		data_init(&table);
		philo_debug(&table); //
		dinner_start(&table);
		cleanup(&table);
		error_exit("Success"); //
	}
	else
		error_exit("Usage: ./philo number_of_philos time_to_die time_to_eat time_to_sleep [meal_amount]");
}
