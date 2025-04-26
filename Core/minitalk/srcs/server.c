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

void	display_and_clean(char **message)
{
	if (!message || !*message)
		return ;
	ft_printf("%s\n", *message);
	free (*message);
	*message = NULL;
	ft_printf("Message has been received!\n");
}

int	make_message(char c)
{
	static char	*message = NULL;
	char	*tmp;

	tmp = NULL;
	if (!message)
	{
		message = ft_strdup(&c);
		if (!message)
		{
			ft_putstr_fd("Failed to allocate message in server.c make_message().", 2);
			return (1);
		}
	}
	if (!c)
		display_and_clean(&message);
	else
	{
		tmp = message;
		message = ft_strjoin(tmp, &c);
		free(tmp);
		tmp = NULL;
		if (!message)
		{
			ft_putstr_fd("Failed to allocate contacenated message in server.c make_message().", 2);
			return (1);
		}
	}
	return (0);
}

void	handle_signal(int signum)
{
	static unsigned	char_received = 0;
	static int		bits  = 0;

	if (signum == SIGUSR2)
		char_received |= (1 << bits);
	bits++;
	if (bits == 8)
	{
		if (make_message(char_received))
		{
			ft_putstr_fd("Failed to allocate message in server.c at handle_signal().", 2);
			exit(1);
		}
		bits = 0;
		char_received = 0;
	}
}

int	main(void)
{
	struct sigaction act;

	act.sa_handler = &handle_signal;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}