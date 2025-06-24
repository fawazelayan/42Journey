/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 03:31:28 by felayan           #+#    #+#             */
/*   Updated: 2025/06/23 03:31:29 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_data *dt)
{
	int	i;

	i = 0;
	if (dt -> ph_num == 1)
	{
		if (thr_ops(&dt -> philos[0].thr, im_mr_lonely,
				&dt -> philos[0], CRT))
			return (print_err_ret("philo thread failed to get created", 1));
	}
	else
	{
		while (i < dt -> ph_num)
		{
			if (thr_ops(&dt ->philos[i].thr, dine_in, &dt -> philos[i], CRT))
				return (detach_on_fail(dt, i));
			i++;
		}
	}
	if (thr_ops(&dt -> monitor, monitoring, dt, CRT))
		return (detach_on_fail(dt, i));
	return (0);
}

int	join_threads(t_data *dt)
{
	int	i;

	i = 0;
	while (i < dt -> ph_num)
	{
		if (thr_ops(&dt -> philos[i++].thr, NULL, NULL, JOIN))
		{
			set_bool(&dt -> dat_lk, &dt -> ended, true);
			return (print_err_ret("philos threads failed to join", 1));
		}
	}
	return (0);
}

void	wait_threads(t_data *dt)
{
	while (!get_bool(&dt -> dat_lk, &dt -> wait))
	{
		if (sim_fin(dt))
			return ;
		usleep(42);
	}
}

void	de_synchro(t_philo *ph)
{
	if (ph -> table -> ph_num % 2 == 0)
	{
		if (ph -> id % 2 == 0)
			precise_usleep(ph -> table, 10);
	}
	else
	{
		if (ph -> id % 2)
			think(ph, false);
	}
}

int	unlock_on_err(t_philo *ph, char *err, t_fork_state st)
{
	if (st == BOTH)
	{
		mutex_opers(&ph -> first -> mutex, UNLOCK);
		mutex_opers(&ph -> second -> mutex, UNLOCK);
	}
	else if (st == FIRST)
		mutex_opers(&ph -> first -> mutex, UNLOCK);
	else if (st == SECOND)
		mutex_opers(&ph -> second -> mutex, UNLOCK);
	return (print_err_ret(err, 1));
}
