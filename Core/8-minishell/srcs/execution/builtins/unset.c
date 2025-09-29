/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:41:48 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/09/26 01:08:40 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_key_index(char **envp, const char *key)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(key);
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], key, len)
			&& (envp[i][len] == '=' || envp[i][len] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

static void	remove_var(t_shell *sh, int index)
{
	int	entries;

	entries = count_env_entries(sh -> envp);
	free(sh -> envp[index]);
	while (index < entries)
	{
		sh -> envp[index] = sh -> envp[index + 1];
		index++;
	}
}

int	unset_cmd(char **args, t_shell *shell)
{
	int		i;
	int		index;
	char	*eq;

	i = 1;
	while (args[i])
	{
		eq = ft_strchr(args[i], '=');
		if (!eq)
		{
			index = find_key_index(shell -> envp, args[i]);
			if (index >= 0)
				remove_var(shell, index);
		}
		i++;
	}
	shell -> exit = 0;
	return (SUCCESS);
}
