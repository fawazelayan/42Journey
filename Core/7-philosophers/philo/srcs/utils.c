/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:14:47 by felayan           #+#    #+#             */
/*   Updated: 2025/06/14 15:14:48 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *error)
{
	write(2, "\nError: ", 8);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
}

void	print_action(t_philo *ph, long stamp, char *act)
{
	pthread_mutex_lock(&ph -> table -> prt_lk);
	if (!ft_strcmp(act, "has taken a fork"))
		printf(CYN"%ld\tPhilo %d\t%s\n"RST, stamp, ph -> id, act);
	else if (!ft_strcmp(act, "is eating"))
		printf(GRN"%ld\tPhilo %d\t%s\n"RST, stamp, ph -> id, act);
	else if (!ft_strcmp(act, "is sleeping"))
		printf(PRP"%ld\tPhilo %d\t%s\n"RST, stamp, ph -> id, act);
	else if (!ft_strcmp(act, "is thinking"))
		printf(YLW"%ld\tPhilo %d\t%s\n"RST, stamp, ph -> id, act);
	else if (!ft_strcmp(act, "has died"))
		printf(RED"%ld\tPhilo %d\t%s\n"RST, stamp - ph -> table -> st, ph -> id, act);
	pthread_mutex_unlock(&ph -> table -> prt_lk);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atol(char *str)
{
	int		digit;
	int		i;
	long	num;

	i = 0;
	num = 0;
	digit = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		digit = str[i] - '0';
		if (num > (LONG_MAX - digit) / 10)
			return (-1);
		num = num * 10 + digit;
		i++;
	}
	return (num);
}

long	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000L) + (time.tv_usec / 1000));
}
