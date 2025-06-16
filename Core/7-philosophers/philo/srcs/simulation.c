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

void	*start_sim(void *philo)
{
	t_philo	*ph;
	long	elapsed_time;

	ph = (t_philo *)philo;
	elapsed_time = get_time_in_ms() - ph -> table -> st;
	if (ph -> table -> ended)
		return (NULL);
	while (!ph -> table -> ended)
	{
		//philo_take
		is_eating(ph);
		is_sleeping(ph);
		is_dead(ph);
	}
	return (NULL);
}
