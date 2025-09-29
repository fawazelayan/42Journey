/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 03:12:03 by felayan           #+#    #+#             */
/*   Updated: 2025/09/25 18:33:13 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_path(char *path, bool *found)
{
	if (!path)
		return (MALC_FAIL);
	if (access(path, F_OK) == 0)
	{
		*found = true;
		if (access(path, X_OK) == 0)
			return (0);
	}
	return (1);
}

static char	*check_status(char *path, char *cmd, bool found, t_shell *sh)
{
	if (!cmd[0])
	{
		free(path);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		sh -> exit = 127;
		return (NULL);
	}
	if (!path)
	{
		if (found)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(cmd, 2);
			ft_putstr_fd(": Pemission denied\n", 2);
			sh -> exit = 126;
		}
		else
		{
			ft_putstr_fd(cmd, 2);
			ft_putstr_fd(": command not found\n", 2);
			sh -> exit = 127;
		}
	}
	return (path);
}

static char	*get_cmd_assist(char *cmd, char *dir)
{
	char	*full_path;

	full_path = malloc(ft_strlen(dir) + ft_strlen(cmd) + 2);
	if (!full_path)
		return (NULL);
	ft_strcpy(full_path, dir);
	ft_strcat(full_path, "/");
	ft_strcat(full_path, cmd);
	return (full_path);
}

static char	*get_cmd_path(char *cmd, t_shell *sh)
{
	char	*full_path;
	char	**dir;
	bool	found;
	int		i;
	char	*paths;

	i = -1;
	found = false;
	paths = get_env_value("PATH", sh -> envp);
	if (!paths || !paths[0])
		return (ret_fail(&paths, cmd, sh));
	dir = ft_split(paths, ':');
	free(paths);
	if (!dir)
		return (NULL);
	while (dir[++i])
	{
		full_path = get_cmd_assist(cmd, dir[i]);
		if (!check_path(full_path, &found))
			break ;
		free(full_path);
		full_path = NULL;
	}
	clean_strs(dir);
	return (check_status(full_path, cmd, found, sh));
}

char	*resolve_path(char *cmd, t_shell *shell)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) != 0)
		{
			ft_putstr_fd("minishell: ", 2);
			perror(cmd);
			shell -> exit = 127;
			return (NULL);
		}
		if (access(cmd, X_OK) != 0)
		{
			ft_putstr_fd("minishell: ", 2);
			perror(cmd);
			shell -> exit = 126;
			return (NULL);
		}
		return (ft_strdup(cmd));
	}
	return (get_cmd_path(cmd, shell));
}
