/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 01:20:35 by felayan           #+#    #+#             */
/*   Updated: 2025/09/26 01:08:03 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parent_exec_sigquit(int sig)
{
	(void)sig;
	write(1, "Quit (core dumped)\n", 19);
}

void	parent_exec_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
}

void	doc_sigint(int sig)
{
	(void)sig;
	g_sig = 130;
	write(1, "\n", 1);
	close(STDIN_FILENO);
}

void	prompt_sigint(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_sig = 130;
}
