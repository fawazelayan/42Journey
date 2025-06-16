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
	if (validation(ac, av))
	{
		printf(RED"Usage: ./philo PHILOSNUM TOD TOE TOS [MEALSNUM]\n\n"RST);
		return (1);
	}
	if (init_data(&data, ac, av))
	{
		print_error("data init fail.");
		return (1);
	}
	pthread_join(data.death, NULL);
	// while (!data.ended)
	// 	usleep(5000);
	clean_sim(&data, data.philos_num);
	return (0);
}
