/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:42:19 by felayan           #+#    #+#             */
/*   Updated: 2025/06/12 19:42:20 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	memset(&data, 0, sizeof(data));
	if (!is_valid_prog(ac, av))
	{
		printf(RED"Usage: ./philo PHILOSNUM TOD TOE TOS [MEALSNUM]\n\n"RST);
		return (1);
	}
	if (init_data(&data, ac, &av[1]))
		return (print_error_ret("data init failed", 1));
	if (start_sim(&data))
		return (print_error_ret("simulation failed to start", 1));
	clean_sim(&data);
	return (0);
}
