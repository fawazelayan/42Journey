/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:54:04 by felayan           #+#    #+#             */
/*   Updated: 2025/06/15 21:54:05 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_memory(t_data *data)
{
	if (data -> forks)
	{
		free(data->forks);
		data -> forks = NULL;
	}
	if (data -> philos)
	{
		free(data->philos);
		data -> philos = NULL;
	}
}

int	detach_on_fail(t_data *data, int count)
{
	int	i;

	i = 0;
	set_bool(&data -> dat_lk, &data -> ended, true);
	while (i < count)
	{
		if (thr_ops(&data -> philos[i].thr, NULL, NULL, DETACH))
			print_err_ret("detaching failed", 1);
		i++;
	}
	if (count < data -> ph_num)
		return (print_err_ret("philo threads failed to get created", 1));
	return (print_err_ret("monitor thread failed to get created", 1));
}

int	clean_mutex(t_data *data)
{
	t_philo	*ph;
	int		failed;
	int		i;

	i = 0;
	failed = 0;
	while (i < data -> ph_num)
	{
		ph = data -> philos + i;
		if (mutex_opers(&ph -> eat_lk, DESTROY))
			failed = print_err_ret("philo mutex failed to destroy", 1);
		if (mutex_opers(&data -> forks[i].mutex, DESTROY))
			failed = print_err_ret("fork mutex failed to destroy", 1);
		i++;
	}
	if (mutex_opers(&data -> dat_lk, DESTROY))
		failed = print_err_ret("data mutex failed to destroy", 1);
	if (mutex_opers(&data -> prt_lk, DESTROY))
		failed = print_err_ret("print mutex failed to destroy", 1);
	return (failed);
}
