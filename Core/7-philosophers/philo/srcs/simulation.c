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

static void	eat(t_philo *ph)
{
	if (sim_fin(ph -> table))
		return ;
	mutex_opers(&ph -> first -> mutex, LOCK);
	print_action(ph, TAKEN_FST);
	mutex_opers(&ph -> scnd -> mutex, LOCK);
	print_action(ph, TAKE_SEC);
	set_long(&ph -> eat_lk, &ph -> lmt, get_time_in_ms());
	ph -> ml_cnt++;
	print_action(ph, EAT);
	precise_usleep(ph -> table, ph -> table -> toe);
	if (ph -> ml_cnt ==  ph -> table -> ml_num)
		set_bool(&ph -> eat_lk, &ph -> full, true);
	mutex_opers(&ph -> first -> mutex, UNLOCK);
	mutex_opers(&ph -> scnd -> mutex, UNLOCK);
}

void	*im_mr_lonely(void *data)
{
	t_philo *ph;

	ph = (t_philo *)data;
	wait_threads(ph -> table);
	set_long(&ph -> eat_lk, &ph -> lmt, get_time_in_ms());
	increase_long(&ph -> table -> dat_lk, &ph -> table -> th_up);
	print_action(ph, TAKEN_FST);
	while (!sim_fin(ph -> table))
		usleep(200);
	return (NULL);
}
void	think(t_philo *ph, bool in_dinner)
{
	long	tot;

	tot = 0;
	if (sim_fin(ph -> table))
		return ;
	if (in_dinner)
		print_action(ph, THINK);
	if (ph -> table -> ph_num % 2 == 0)
		return ;
	tot = ph -> table -> toe * 2 - ph -> table -> tos;
	if (tot < 0)
		tot = 0;
	precise_usleep(ph -> table, tot * 0.42);
	if (sim_fin(ph -> table))
		return ;
}

void	*start_dinner(void *philo)
{
	t_philo *ph;
	
	ph = (t_philo *)philo;
	wait_threads(ph -> table);
	set_long(&ph -> eat_lk, &ph -> lmt, get_time_in_ms());
	increase_long(&ph -> table -> dat_lk, &ph -> table -> th_up);
	de_synchro(ph);
	while (!sim_fin(ph -> table))
	{
		if (ph -> full)
			break ;
		eat(ph);
		print_action(ph, SLEEP);
		precise_usleep(ph -> table, ph -> table -> tos);
		think(ph, true);
	}
	return (NULL);
}

void	start_sim(t_data *data)
{
	int	i;

	i = 0;
	if (data -> ph_num == 1)
		thread_opers(&data -> philos[0].thread, im_mr_lonely,
			&data -> philos[0], CRT); // TODO
	else
	{
		while (i < data -> ph_num)
		{
			thread_opers(&data ->philos[i].thread, start_dinner, &data -> philos[i], CRT);
			i++;
		}
	}
	thread_opers(&data -> monitor, monitoring, data, CRT);
	data -> st = get_time_in_ms();
	set_bool(&data -> dat_lk, &data -> wait, true);
	i = 0;
	while (i < data -> ph_num)
		thread_opers(&data -> philos[i++].thread, NULL, NULL, JOIN);
	set_bool(&data -> dat_lk, &data -> ended, true);
	thread_opers(&data -> monitor, NULL, NULL, DETACH);
}
