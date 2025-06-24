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
		return (print_err_ret("Usage: ./philo PHNUM TOD TOE TOS [MLSNUM]", 1));
	if (init_data(&data, ac, &av[1]))
	{
		clean_memory(&data);
		return (print_err_ret("data init failed", 1));
	}
	if (start_sim(&data))
	{
		clean_memory(&data);
		if (clean_mutex(&data))
			return (print_err_ret("cleaning after sim start failed", 1));
		return (print_err_ret("simulation failed to start", 1));
	}
	if (clean_mutex(&data))
	{
		clean_memory(&data);
		return (print_err_ret("cleaning failed", 1));
	}
	clean_memory(&data);
	return (0);
}
