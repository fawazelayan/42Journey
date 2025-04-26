/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 03:09:50 by felayan           #+#    #+#             */
/*   Updated: 2025/04/26 03:09:52 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	send_message(int pid, char char_sent)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((char_sent >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50);
		i++;
	}
}
int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	pid = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client <PID> <Message>\n", 2);
		exit (1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		send_message(pid, argv[2][i]);
		i++;
	}
	send_message(pid, '\0');
}
