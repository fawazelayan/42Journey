/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:40:28 by felayan           #+#    #+#             */
/*   Updated: 2025/06/13 20:40:29 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_locks(t_data *data)
{
	if (pthread_mutex_init(&data -> end_lk, NULL))
		return (1);
	if (pthread_mutex_init(&data -> prt_lk, NULL))
	{
		pthread_mutex_destroy(&data -> end_lk);
		return (1);
	}
	if (pthread_mutex_init(&data -> eat_lk, NULL))
	{
		pthread_mutex_destroy(&data -> end_lk);
		pthread_mutex_destroy(&data -> prt_lk);
		return (1);
	}
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data -> forks = malloc(sizeof(t_fork) * data -> philos_num);
	if (!data -> forks)
		return (1);
	while (i < data -> philos_num)
	{
		if (pthread_mutex_init(&data -> forks[i].mutex, NULL))
		{
			destroy_mutex(data -> forks, i);
			return (1);
		}
		data -> forks[i].id = i;
		i++;
	}
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;
	int	num;

	i = 0;
	num = data -> philos_num;
	data -> philos = malloc(sizeof(t_philo) * num);
	if (!data -> philos)
		return (1);
	while (i < num)
	{
		data -> philos[i].left = &data -> forks[(i - 1 + num) % num];
		data -> philos[i].right = &data -> forks[i];
		data -> philos[i].meal_cntr = 0;
		data -> philos[i].table = data;
		data -> philos[i].full = 0;
		data -> philos[i].lmt = 0;
		data -> philos[i].id = i;
		if (pthread_create(&data -> philos[i].thread, NULL,
				start_sim, &data -> philos[i]))
			return (clean_sim(data, i));
		i++;
	}
	detach_thread(data -> philos, num);
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	data -> philos_num = ft_atol(av[1]);
	data -> tod = ft_atol(av[2]);
	data -> toe = ft_atol(av[3]);
	data -> tos = ft_atol(av[4]);
	data -> meals_num = -1;
	if (ac == 6)
		data -> meals_num = ft_atol(av[5]);
	if (data -> philos_num < 1 || (data -> meals_num < 1 && ac == 6)
		|| data -> tod < 1 || data -> toe < 1 || data -> tos < 1)
		return (1);
	data -> st = get_time_in_ms();
	data -> et = 0;
	data -> ended = 0;
	if (init_locks(data))
		return (1);
	if (init_forks(data))
		return (1);
	if (init_philos(data))
		return (1);
	return (0);
}
