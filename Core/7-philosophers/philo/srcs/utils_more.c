/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 03:31:38 by felayan           #+#    #+#             */
/*   Updated: 2025/06/23 03:31:40 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_input(t_data *data, int ac, char **av)
{
	data -> ph_num = ft_atol(av[0]);
	data -> tod = ft_atol(av[1]);
	data -> toe = ft_atol(av[2]);
	data -> tos = ft_atol(av[3]);
	data -> ml_num = -1;
	if (ac == 6)
		data -> ml_num = ft_atol(av[4]);
}

int	mutex_opers(t_mtx *mtx, t_code code)
{
	if (code == INIT)
	{
		if (pthread_mutex_init(mtx, NULL))
			return (print_error_ret("mutex failed to init", 1));
	}
	else if (code == LOCK)
	{
		if (pthread_mutex_lock(mtx))
			return (print_error_ret("mutex failed to lock", 1));
	}
	else if (code == UNLOCK)
	{
		if (pthread_mutex_unlock(mtx))
			return (print_error_ret("mutex failed to unlock", 1));
	}
	else if (code == DESTROY)
	{
		if (pthread_mutex_destroy(mtx))
			return (print_error_ret("mutex failed to destroy", 1));
	}
	return (0);
}

int	thr_ops(t_thr *thr, void *(*foo)(void *), void *data, t_code cd)
{
	if (cd == CRT)
	{
		if (pthread_create(thr, NULL, foo, data))
			return (print_error_ret("thread failed to create", 1));
	}
	else if (cd == JOIN)
	{
		if (pthread_join(*thr, NULL))
			return (print_error_ret("thread failed to join", 1));
	}
	return (0);
}

void	precise_usleep(t_data *data, long time)
{
	long	start;

	start = get_time_in_ms();
	if (sim_fin(data))
		return ;
	while (get_time_in_ms() - start < time)
	{
		if (get_bool(&data -> dat_lk, &data -> ended))
			break ;
		usleep(100);
	}
}

void	increase_long(t_mtx *mtx, long *val)
{
	mutex_opers(mtx, LOCK);
	(*val)++;
	mutex_opers(mtx, UNLOCK);
}
