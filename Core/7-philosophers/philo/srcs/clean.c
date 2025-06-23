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

int	clean_sim(t_data *data)
{
	t_philo	*ph;
	int		i;

	i = 0;
	while (i < data -> ph_num)
	{
		ph = data -> philos + i;
		if (mutex_opers(&ph -> eat_lk, DESTROY))
			return (print_error_ret("philo mutex failed to destroy", 1));
		if (mutex_opers(&data -> forks[i].mutex, DESTROY))
			return (print_error_ret("fork mutex failed to destroy", 1));
		i++;
	}
	if (mutex_opers(&data -> dat_lk, DESTROY))
		return (print_error_ret("data mutex failed to destroy", 1));
	if (mutex_opers(&data -> prt_lk, DESTROY))
		return (print_error_ret("print mutex failed to destroy", 1));
	free(data -> forks);
	free(data -> philos);
	return (0);
}
