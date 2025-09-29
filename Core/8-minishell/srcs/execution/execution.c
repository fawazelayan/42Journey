/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:23:45 by moaljazz          #+#    #+#             */
/*   Updated: 2025/09/26 01:05:19 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_pipes(t_shell *sh)
{
	t_cmd	*tmp;

	tmp = sh -> cmds;
	while (tmp)
	{
		tmp -> fds[0] = -1;
		tmp -> fds[1] = -1;
		if (tmp -> next)
		{
			if (pipe(tmp -> fds) < 0)
			{
				perror("minishell: pipe");
				sh -> exit = errno;
				close_fds();
				return (sh -> exit);
			}
		}
		tmp = tmp -> next;
	}
	return (SUCCESS);
}

int	built_ins(t_cmd *cmd, t_shell *shell)
{
	if (!ft_strcmp(cmd -> args[0], "cd"))
		return (cd_cmd(cmd -> args, shell));
	if (!ft_strcmp(cmd -> args[0], "exit"))
	{
		exit_cmd(cmd, shell);
		return (SUCCESS);
	}
	if (!ft_strcmp(cmd -> args[0], "echo"))
		return (echo_cmd(cmd -> args));
	if (!ft_strcmp(cmd -> args[0], "export"))
		return (export_cmd(cmd -> args, shell));
	if (!ft_strcmp(cmd -> args[0], "unset"))
		return (unset_cmd(cmd -> args, shell));
	if (!ft_strcmp(cmd -> args[0], "env"))
		return (env_cmd(shell, cmd));
	if (!ft_strcmp(cmd -> args[0], "pwd"))
		return (pwd_cmd(shell));
	return (1);
}

static void	parent_builtin_exec(t_shell *sh, t_cmd *cmd)
{
	int	stdfd[2];

	stdfd[0] = dup(STDIN_FILENO);
	stdfd[1] = dup(STDOUT_FILENO);
	if (stdfd[0] < 0 || stdfd[1] < 0)
	{
		perror("minishell: dup");
		sh -> exit = errno;
		close_pair(stdfd);
		return ;
	}
	if (open_dup_fds(STDIN_FILENO, STDOUT_FILENO, sh, cmd) == SUCCESS)
		built_ins(cmd, sh);
	if (dup2(stdfd[0], STDIN_FILENO) < 0 || dup2(stdfd[1], STDOUT_FILENO) < 0)
	{
		perror("minishell: dup");
		sh -> exit = errno;
		close_pair(stdfd);
		return ;
	}
	close_pair(stdfd);
}

void	execution(t_shell *sh)
{
	t_cmd	*cmd;
	t_cmd	*prev;

	prev = NULL;
	cmd = sh -> cmds;
	if (init_pipes(sh))
		return ;
	if (sh -> cmd_count == 1 && is_parent_builtin(cmd -> args[0]))
	{
		parent_builtin_exec(sh, cmd);
		clean_cmds(sh -> cmds);
		sh -> cmds = NULL;
		return ;
	}
	while (cmd)
	{
		sh -> exit = 0;
		if (child_fork(cmd, prev, sh))
			return ;
		prev = cmd;
		cmd = cmd -> next;
	}
	close_and_wait(sh);
	clean_cmds(sh -> cmds);
	sh -> cmds = NULL;
}
