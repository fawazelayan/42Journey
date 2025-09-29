/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:17:20 by felayan           #+#    #+#             */
/*   Updated: 2025/09/26 01:08:03 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_sig = 0;

void	prompt_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = prompt_sigint;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGQUIT, &sa, NULL);
}

void	child_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	parent_exec_signals(void)
{
	signal(SIGINT, parent_exec_sigint);
	signal(SIGQUIT, parent_exec_sigquit);
}

void	doc_signals(void)
{
	signal(SIGINT, doc_sigint);
	signal(SIGQUIT, SIG_IGN);
}
