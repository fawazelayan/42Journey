/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:25:19 by moaljazz          #+#    #+#             */
/*   Updated: 2025/09/26 01:06:07 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_exec(t_shell *sh, t_cmd *curr, t_cmd *prev)
{
	int		fd_in;
	int		fd_out;
	t_cmd	*tmp;

	tmp = sh -> cmds;
	fd_in = STDIN_FILENO;
	fd_out = STDOUT_FILENO;
	if (prev)
		fd_in = prev -> fds[0];
	if (curr -> next)
		fd_out = curr -> fds[1];
	child_signals();
	if (open_dup_fds(fd_in, fd_out, sh, curr))
		clean_shell(sh, sh -> exit);
	while (tmp)
	{
		if (tmp != prev && tmp -> fds[0] >= 0)
			close(tmp -> fds[0]);
		if (tmp != curr && tmp -> fds[1] >= 0)
			close(tmp -> fds[1]);
		tmp = tmp -> next;
	}
	cmd_exec(curr, sh);
	clean_shell(sh, sh -> exit);
}

int	child_fork(t_cmd *cmd, t_cmd *prev, t_shell *sh)
{
	cmd -> pid = fork();
	if (cmd -> pid < 0)
	{
		perror("minshell: fork");
		sh -> exit = errno;
		return (sh -> exit);
	}
	if (!cmd -> pid)
		child_exec(sh, cmd, prev);
	else
	{
		if (!cmd -> next)
			sh -> last_cmd_pid = cmd -> pid;
		parent_exec_signals();
	}
	return (SUCCESS);
}

static bool	is_dir(char *arg, int *status)
{
	int	fd;

	fd = -1;
	fd = open(arg, O_RDWR);
	if (fd < 0 && errno == EISDIR)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(arg);
		*status = 126;
		return (true);
	}
	else if (fd >= 0)
		close(fd);
	return (false);
}

void	cmd_exec(t_cmd *cmd, t_shell *shell)
{
	if (!built_ins(cmd, shell))
		return ;
	if (!cmd -> args[0])
		return ;
	if (is_dir(cmd -> args[0], &shell -> exit))
		return ;
	cmd -> cmd_path = resolve_path(cmd -> args[0], shell);
	if (!cmd -> cmd_path)
		return ;
	if (execve(cmd -> cmd_path, cmd -> args, shell -> envp) < 0)
	{
		shell -> exit = errno;
		return ;
	}
}
