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

static void	assign_forks(t_philo *philo, t_fork *fork, int pos)
{
	int	num;

	num = philo -> table -> ph_num;
	philo -> first = &fork[pos];
	philo -> scnd = &fork[(pos - 1 + num) % num];
	if (philo -> id % 2 != 0)
	{
		philo -> first = &fork[(pos - 1 + num) % num];
		philo -> scnd = &fork[pos];
	}
}

static int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data -> ph_num)
	{
		data -> philos[i].id = i;
		data -> philos[i].full = false;
		data -> philos[i].ml_cnt = 0;
		if (mutex_opers(&data -> philos[i].eat_lk, INIT))
			return (print_error_ret("philo mutex failed to init", 1));
		data -> philos[i].table = data;
		assign_forks(&data ->philos[i], data -> forks, i);
		i++;
	}
	return (0);
}

static int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data -> ph_num)
	{
		if (mutex_opers(&data -> forks[i].mutex, INIT))
			return (print_error_ret("fork mutex failed to init", 1));
		data -> forks[i].id = i;
		i++;
	}
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	parse_input(data, ac, av);
	if (data -> ph_num < 1 || (data -> ml_num < 1 && ac == 6)
		|| data -> tod < 60 || data -> toe < 60 || data -> tos < 60)
		return (print_error_ret("invalid values while parsing", 1));
	data -> philos = malloc(sizeof(t_philo) * data -> ph_num);
	if (!data -> philos)
		return (print_error_ret("philos array failed to allocate mem", 1));
	data -> forks = malloc(sizeof(t_fork) * data -> ph_num);
	if (!data -> forks)
	{
		free(data -> philos);
		return (print_error_ret("forks array failed to allocate mem", 1));
	}
	if (init_forks(data))
		return (print_error_ret("forks failed to init", 1));
	if (mutex_opers(&data -> dat_lk, INIT))
		return (print_error_ret("data mutex failed to init", 1));
	if (mutex_opers(&data -> prt_lk, INIT))
		return (print_error_ret("print mutex failed to init", 1));
	if (init_philos(data))
		return ("philos failed to init", 1);
	return (0);
}
