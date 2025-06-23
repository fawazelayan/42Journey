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

int	print_error_ret(char *error, int ret)
{
	write(2, "\nError: ", 8);
	write(2, error, str_len(error));
	write(2, ".\n\n", 3);
	return (ret);
}

int	print_action(t_philo *ph, t_ph_status st)
{
	long	stamp;

	stamp = get_time_in_ms() - ph -> table -> st;
	if (ph -> full)
		return (0);
	if (mutex_opers(&ph -> table -> prt_lk, LOCK))
		return (print_error_ret("print failed to lock", 1));
	if ((st == TAKEN_FST || st == TAKE_SEC) && !sim_fin(ph -> table))
		printf(YLW"%ld\tPhilo %d has taken a fork\n"RST, stamp, ph -> id);
	else if (st == EAT && !sim_fin(ph -> table))
		printf(GRN"%ld\tPhilo %d is eating\n"RST, stamp, ph -> id);
	else if (st == SLEEP && !sim_fin(ph -> table))
		printf(PRP"%ld\tPhilo %d is sleeping\n"RST, stamp, ph -> id);
	else if (st == THINK && !sim_fin(ph -> table))
		printf(CYN"%ld\tPhilo %d is thinking\n"RST, stamp, ph -> id);
	else if (st == DEAD && sim_fin(ph -> table))
		printf(RED"%ld\tPhilo %d has died\n"RST, stamp, ph -> id);
	if (mutex_opers(&ph -> table -> prt_lk, UNLOCK))
		return (print_error_ret("print failed to unlock", 1));
	return (0);
}

int	str_len(char *str)
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
		if (num > INT_MAX)
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
