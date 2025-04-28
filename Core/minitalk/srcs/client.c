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

#include "minitalk.h"

volatile sig_atomic_t	g_ack = 0;

void	send_char(int pid, unsigned char char_sent)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ack = 0;
		if ((char_sent >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack)
			usleep(50);
		i++;
	}
}

void	encrypt_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		send_char(pid, (unsigned char)message[i]);
		i++;
	}
	send_char(pid, '\0');
}

void	check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i] != '\0')
	{
		if (!ft_isdigit(pid[i]))
		{
			ft_putstr_fd("\nError: PID is not a number.\n\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ack_handle(int signum)
{
	if (signum == SIGUSR2)
		g_ack = 1;
	else
		g_ack = 2;
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	act.sa_handler = &ack_handle;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	if (argc != 3)
	{
		ft_putstr_fd("\nError: Wrong number of arguments.", 2);
		ft_putstr_fd("\nUsage: ./client <server_PID> <MESSAGE>\n\n", 2);
		exit(EXIT_FAILURE);
	}
	check_pid(argv[1]);
	encrypt_message(ft_atoi(argv[1]), argv[2]);
	while (g_ack != 2)
		usleep(50);
	ft_putstr_fd("\nMessage Received!\n\n", 1);
}
