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

void	destroy_mutex(t_fork *forks, int cnt)
{
	int	i;

	i = 0;
	if (!forks)
		return ;
	while (i < cnt)
	{
		pthread_mutex_destroy(&forks[i].mutex);
		i++;
	}
	free(forks);
}

void	join_thread(t_philo *philos, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

void	detach_thread(t_philo *philos, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		pthread_detach(philos[i].thread);
		i++;
	}
}

int	clean_sim(t_data *data, int cnt)
{
	if (!data)
		return (1);
	if (data -> forks)
	{
		destroy_mutex(data -> forks, data -> philos_num);
		data -> forks = NULL;
	}
	if (data -> philos)
	{
		if (cnt < data -> philos_num)
		{
			data -> ended = 1;
			join_thread(data -> philos, cnt);
		}
		free(data -> philos);
		data -> philos = NULL;
	}
	return (1);
}
