/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:23:11 by moaljazz          #+#    #+#             */
/*   Updated: 2025/09/26 22:05:54 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_file(char *file, t_rdr type, int *status)
{
	int	fd;

	fd = -1;
	if (file)
	{
		if (type == IN)
			fd = open(file, O_RDONLY);
		else if (type == OUT)
			fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (type == APPEND)
			fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	}
	else
		return (-2);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(file);
		*status = 1;
	}
	return (fd);
}

static int	dup_fd(int fd, bool in, int *status)
{
	if (fd != STDIN_FILENO && in)
	{
		if (dup2(fd, STDIN_FILENO) < 0)
		{
			perror("minishell: dup");
			*status = errno;
			close(fd);
			return (1);
		}
		close(fd);
	}
	else if (fd != STDOUT_FILENO && !in)
	{
		if (dup2(fd, STDOUT_FILENO) < 0)
		{
			perror("minishell: dup");
			*status = errno;
			close(fd);
			return (1);
		}
		close(fd);
	}
	return (SUCCESS);
}

int	open_dup_fds(int fd_in, int fd_out, t_shell *sh, t_cmd *cmd)
{
	t_redir	*rdr;
	int		i;
	int		fd;

	i = 0;
	rdr = cmd -> redir;
	if (dup_fd(fd_in, true, &sh -> exit) || dup_fd(fd_out, false, &sh -> exit))
		return (1);
	while (i < cmd -> redir_count)
	{
		fd = open_file(rdr[i].filename, rdr[i].type, &sh -> exit);
		if (fd == -1)
			return (1);
		if (fd == -2)
		{
			if (rdr[i].doc_fd >= 0 && dup_fd(rdr[i].doc_fd, true, &sh -> exit))
				return (1);
		}
		else if (rdr[i].type == IN && dup_fd(fd, true, &sh -> exit))
			return (1);
		else if (rdr[i].type != IN && dup_fd(fd, false, &sh -> exit))
			return (1);
		i++;
	}
	return (SUCCESS);
}
