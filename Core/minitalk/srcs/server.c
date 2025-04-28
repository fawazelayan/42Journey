/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 02:05:03 by felayan           #+#    #+#             */
/*   Updated: 2025/04/26 02:05:05 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	display(char char_received)
{
	if (char_received)
	{
		write(1, &char_received, 1);
		return (0);
	}
	else
		write(1, "\n\n", 2);
	return (1);
}

void	sigusr_handle(int signum, siginfo_t *info, void *context)
{
	static char		char_received = 0;
	static int		bits_shifted = 0;
	static pid_t	client_pid = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (signum == SIGUSR1)
		char_received |= (1 << bits_shifted);
	bits_shifted++;
	if (bits_shifted == 8)
	{
		if (display(char_received))
		{
			kill(client_pid, SIGUSR1);
			client_pid = 0;
			char_received = 0;
			bits_shifted = 0;
			return ;
		}
		char_received = 0;
		bits_shifted = 0;
	}
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("\nServer is online and the PID is: [%d]\n\n", getpid());
	act.sa_handler = NULL;
	act.sa_sigaction = &sigusr_handle;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
