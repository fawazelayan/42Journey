/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:55:24 by felayan           #+#    #+#             */
/*   Updated: 2025/06/15 21:55:25 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat(t_philo *ph)
{
	if (sim_fin(ph -> table))
		return ;
	if (mutex_opers(&ph -> first -> mutex, LOCK))
		return (print_error_ret("first fork failed to lock", 1));
	if (print_action(ph, TAKEN_FST))
		return (print_error_ret("first fork print failed", 1));
	if (mutex_opers(&ph -> scnd -> mutex, LOCK))
		return (print_error_ret("second fork failed to lock", 1));
	if (print_action(ph, TAKE_SEC))
		return (print_error_ret("second fork print failed", 1));
	if (set_long(&ph -> eat_lk, &ph -> lmt, get_time_in_ms()))
		return (print_error_ret("philo mutex failed", 1));
	ph -> ml_cnt++;
	if (print_action(ph, EAT))
		return (print_error_ret("eating print faiked", 1));
	precise_usleep(ph -> table, ph -> table -> toe);
	if (ph -> ml_cnt ==  ph -> table -> ml_num)
	{
		if (set_bool(&ph -> eat_lk, &ph -> full, true))
			return (print_error_ret("philo mutex failed", 1));
	}
	if (mutex_opers(&ph -> first -> mutex, UNLOCK))
		return (print_error_ret("first fork failed to unlock", 1));
	if(mutex_opers(&ph -> scnd -> mutex, UNLOCK))
		return (print_error_ret("second fork failed to unlock", 1));
}

void	*im_mr_lonely(void *data)
{
	t_philo *ph;

	ph = (t_philo *)data;
	wait_threads(ph -> table);
	if (set_long(&ph -> eat_lk, &ph -> lmt, get_time_in_ms()))
		return (print_error_ret("philo mutex failed", 1));
	if (increase_long(&ph -> table -> dat_lk, &ph -> table -> th_up))
		return (print_error_ret("data mutex failed", 1));
	if (print_action(ph, TAKEN_FST))
		return (print_error_ret("first fork print failed", 1));
	while (!sim_fin(ph -> table))
		usleep(200);
	return (NULL);
}
int	think(t_philo *ph, bool in_dinner)
{
	long	tot;

	tot = 0;
	if (sim_fin(ph -> table))
		return ;
	if (in_dinner)
	{
		if (print_action(ph, THINK))
			return (print_error_ret("think print failed", 1));
	}
	if (ph -> table -> ph_num % 2 == 0)
		return ;
	tot = ph -> table -> toe * 2 - ph -> table -> tos;
	if (tot < 0)
		tot = 0;
	precise_usleep(ph -> table, tot * 0.42);
	if (sim_fin(ph -> table))
		return ;
}

void	*dine_in(void *philo)
{
	t_philo *ph;
	
	ph = (t_philo *)philo;
	wait_threads(ph -> table);
	if (set_long(&ph -> eat_lk, &ph -> lmt, get_time_in_ms()))
		return (print_error_ret("philo mutex failed", 1));
	if (increase_long(&ph -> table -> dat_lk, &ph -> table -> th_up))
		return (print_error_ret("data mutex failed", 1));
	de_synchro(ph);
	while (!sim_fin(ph -> table))
	{
		if (ph -> full)
			break ;
		if (eat(ph))
			return (print_error_ret("eating failed", 1));
		if (print_action(ph, SLEEP))
			return (print_error_ret("sleep print failed", 1));
		precise_usleep(ph -> table, ph -> table -> tos);
		if (think(ph, true))
			return (print_error_ret("thinking failed", 1));
	}
	return (NULL);
}

int	start_sim(t_data *data)
{
	if (create_threads(data))
		return (print_error_ret("creating threads failed", 1));
	if (join_threads(data))
		return (print_error_ret("joining threads failed", 1));
	data -> st = get_time_in_ms();
	set_bool(&data -> dat_lk, &data -> wait, true);
	set_bool(&data -> dat_lk, &data -> ended, true);
	if (thr_ops(&data -> monitor, NULL, NULL, JOIN))
		return (print_error_ret("monitor thread failed to join", 1));
	return (0);
}
