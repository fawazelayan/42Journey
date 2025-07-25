/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 03:31:56 by felayan           #+#    #+#             */
/*   Updated: 2025/06/23 03:31:57 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(t_mtx *mtx, bool *set, bool val)
{
	mutex_opers(mtx, LOCK);
	*set = val;
	mutex_opers(mtx, UNLOCK);
}

bool	get_bool(t_mtx *mtx, bool *val)
{
	bool	get;

	mutex_opers(mtx, LOCK);
	get = *val;
	mutex_opers(mtx, UNLOCK);
	return (get);
}

void	set_long(t_mtx *mtx, long *set, long val)
{
	mutex_opers(mtx, LOCK);
	*set = val;
	mutex_opers(mtx, UNLOCK);
}

long	get_long(t_mtx *mtx, long *val)
{
	long	get;

	mutex_opers(mtx, LOCK);
	get = *val;
	mutex_opers(mtx, UNLOCK);
	return (get);
}

bool	sim_fin(t_data *data)
{
	return (get_bool(&data -> dat_lk, &data -> ended));
}
