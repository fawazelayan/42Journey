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

void	clean_sim(t_data *data)
{
	t_philo	*ph;
	int		i;

	i = 0;
	while (i < data -> ph_num)
	{
		ph = data -> philos + i;
		mutex_opers(&ph -> eat_lk, DESTROY);
		mutex_opers(&data -> forks[i].mutex, DESTROY);
		i++;
	}
	mutex_opers(&data -> dat_lk, DESTROY);
	mutex_opers(&data -> prt_lk, DESTROY);
	free(data -> forks);
	free(data -> philos);
}
