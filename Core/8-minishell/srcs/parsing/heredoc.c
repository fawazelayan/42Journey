/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:10:01 by felayan           #+#    #+#             */
/*   Updated: 2025/09/29 05:00:01 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	write_heredoc(char *input, int fd[2], int st, t_shell *shell)
{
	if (st == 1 && ft_strchr(input, '$'))
	{
		shell -> expand = ft_strdup("");
		if (!shell -> expand)
			return (-1);
		if (expand_var(shell, input))
			return (-1);
		free(input);
		input = ft_strdup(shell -> expand);
		free(shell -> expand);
	}
	ft_putstr_fd(input, fd[1]);
	ft_putchar_fd('\n', fd[1]);
	free(input);
	return (SUCCESS);
}

static int	is_expand(t_tkns *delim)
{
	int	status;

	status = 1;
	if (delim -> type == T_DOUBLE || delim -> type == T_SINGLE)
		status = 0;
	return (status);
}

static int	handle_input(char *input, int *fd, t_tkns *delim, t_shell *sh)
{
	if (!input)
	{
		if (g_sig == 130)
		{
			close_pair(fd);
			return (-1);
		}
		ft_putstr_fd("minishell: warning: heredoc terminated by EOF\n", 2);
		return (0);
	}
	if (!ft_strcmp(input, delim -> value))
	{
		free(input);
		return (0);
	}
	if (write_heredoc(input, fd, is_expand(delim), sh) < 0)
	{
		close_pair(fd);
		return (-1);
	}
	return (1);
}

int	open_doc(t_tkns *delim, t_shell *shell)
{
	int		fd[2];
	char	*input;
	int		status;

	status = 0;
	if (pipe(fd) == -1)
		return (-1);
	while (1)
	{
		doc_signals();
		input = readline("> ");
		status = handle_input(input, fd, delim, shell);
		if (status == 0)
			break ;
		else if (status == -1)
			return (-1);
	}
	close(fd[1]);
	return (fd[0]);
}
