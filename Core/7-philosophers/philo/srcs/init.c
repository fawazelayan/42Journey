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

static void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data -> ph_num)
	{
		data -> philos[i].id = i;
		data -> philos[i].full = false;
		data -> philos[i].ml_cnt = 0;
		mutex_opers(&data -> philos[i].eat_lk, INIT);
		data -> philos[i].table = data;
		assign_forks(&data ->philos[i], data -> forks, i);
		i++;
	}
}

int	init_data(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	parse_input(data, ac, av);
	if (data -> ph_num < 1 || (data -> ml_num < 1 && ac == 6)
		|| data -> tod < 60 || data -> toe < 60 || data -> tos < 60)
		return (1);
	data -> philos = malloc(sizeof(t_philo) * data -> ph_num);
	if (!data -> philos)
		return (1);
	data -> forks = malloc(sizeof(t_fork) * data -> ph_num);
	if (!data -> forks)
	{
		free(data -> philos);
		return (1);
	}
	while (i < data -> ph_num)
	{
		mutex_opers(&data -> forks[i].mutex, INIT);
		data -> forks[i].id = i;
		i++;
	}
	mutex_opers(&data -> dat_lk, INIT);
	init_philo(data);
	return (0);
}
