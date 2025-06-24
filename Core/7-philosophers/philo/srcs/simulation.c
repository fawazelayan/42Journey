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
		return (0);
	if (mutex_opers(&ph -> first -> mutex, LOCK))
		return (print_err_ret("first fork failed to lock", 1));
	if (print_action(ph, TAKEN_FST))
		return (unlock_on_err(ph, "first fork print failed", FIRST));
	if (mutex_opers(&ph -> second -> mutex, LOCK))
		return (unlock_on_err(ph, "second fork failed to lock", FIRST));
	if (print_action(ph, TAKE_SEC))
		return (unlock_on_err(ph, "second fork print failed", BOTH));
	set_long(&ph -> eat_lk, &ph -> lmt, get_time_in_ms());
	increase_long(&ph -> eat_lk, &ph -> ml_cnt);
	if (print_action(ph, EAT))
		return (unlock_on_err(ph, "eating print failed", BOTH));
	precise_usleep(ph -> table, ph -> table -> toe);
	if (get_long(&ph -> eat_lk, &ph -> ml_cnt) == ph -> table -> ml_num)
		set_bool(&ph -> eat_lk, &ph -> full, true);
	if (mutex_opers(&ph -> first -> mutex, UNLOCK))
		return (unlock_on_err(ph, "first fork failed to unlock", SECOND));
	if (mutex_opers(&ph -> second -> mutex, UNLOCK))
		return (print_err_ret("second fork failed to unlock", 1));
	return (0);
}

void	*im_mr_lonely(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	wait_threads(ph -> table);
	set_long(&ph -> eat_lk, &ph -> lmt, get_time_in_ms());
	increase_long(&ph -> table -> dat_lk, &ph -> table -> th_up);
	if (sim_fin(ph -> table))
		return (NULL);
	if (print_action(ph, TAKEN_FST))
	{
		set_bool(&ph -> table -> dat_lk, &ph -> table -> ended, true);
		print_err_ret("first fork print failed", 1);
	}
	while (!sim_fin(ph -> table))
		usleep(200);
	return (NULL);
}

int	think(t_philo *ph, bool in_dinner)
{
	long	tot;

	tot = 0;
	if (sim_fin(ph -> table))
		return (0);
	if (in_dinner)
	{
		if (print_action(ph, THINK))
			return (print_err_ret("think print failed", 1));
	}
	if (ph -> table -> ph_num % 2 == 0)
		return (0);
	tot = ph -> table -> toe * 2 - ph -> table -> tos;
	if (tot < 0)
		tot = 0;
	precise_usleep(ph -> table, tot * 0.42);
	return (0);
}

void	*dine_in(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	wait_threads(ph -> table);
	if (sim_fin(ph -> table))
		return (NULL);
	set_long(&ph -> eat_lk, &ph -> lmt, get_time_in_ms());
	increase_long(&ph -> table -> dat_lk, &ph -> table -> th_up);
	de_synchro(ph);
	while (!sim_fin(ph -> table))
	{
		if (get_bool(&ph -> eat_lk, &ph -> full))
			break ;
		if (eat(ph))
			set_bool(&ph -> table -> dat_lk, &ph -> table -> ended, true);
		if (print_action(ph, SLEEP))
			set_bool(&ph -> table -> dat_lk, &ph -> table -> ended, true);
		precise_usleep(ph -> table, ph -> table -> tos);
		if (think(ph, true))
			set_bool(&ph -> table -> dat_lk, &ph -> table -> ended, true);
	}
	return (NULL);
}

int	start_sim(t_data *data)
{
	data -> st = get_time_in_ms();
	if (create_threads(data))
		return (print_err_ret("creating threads failed", 1));
	set_bool(&data -> dat_lk, &data -> wait, true);
	if (join_threads(data))
		return (print_err_ret("joining threads failed", 1));
	set_bool(&data -> dat_lk, &data -> ended, true);
	if (thr_ops(&data -> monitor, NULL, NULL, JOIN))
		return (print_err_ret("monitor thread failed to join", 1));
	return (0);
}
