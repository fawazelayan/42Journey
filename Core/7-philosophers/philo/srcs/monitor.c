/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   th_mtx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 03:31:48 by felayan           #+#    #+#             */
/*   Updated: 2025/06/23 03:31:49 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_dead(t_philo *ph)
{
	long	stamp;

	stamp = get_time_in_ms() - get_long(&ph -> eat_lk, &ph -> lmt);
	if (get_bool(&ph -> eat_lk, &ph -> full))
		return (false);
	if (stamp > ph -> table -> tod)
		return (true);
	return (false);
}

bool	threads_active(t_mtx *mtx, long *th, long ph_num)
{
	bool	ret;

	ret = false;
	mutex_opers(mtx, LOCK);
	if (*th == ph_num)
		ret = true;
	mutex_opers(mtx, UNLOCK);
	return (ret);
}

void	*monitoring(void *data)
{
	t_data	*dt;
	int		i;

	i = 0;
	dt = (t_data *)data;
	while (!threads_active(&dt -> dat_lk, &dt -> th_up, dt -> ph_num))
		usleep(42);
	while (!sim_fin(dt))
	{
		i = 0;
		while (i < dt -> ph_num && !sim_fin(dt))
		{
			if (is_dead(&dt -> philos[i]))
			{
				set_bool(&dt -> dat_lk, &dt -> ended, true);
				print_action(&dt -> philos[i], DEAD);
			}
			i++;
		}
	}
	return (NULL);
}
