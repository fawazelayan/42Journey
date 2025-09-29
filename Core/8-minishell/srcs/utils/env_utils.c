/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:57:43 by felayan           #+#    #+#             */
/*   Updated: 2025/09/29 05:41:15 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_env_entries(char **envp)
{
	int	entries;

	entries = 0;
	while (envp[entries])
		entries++;
	return (entries);
}

char	**get_env_key(t_shell *sh, const char *key)
{
	int		i;
	int		len;
	char	*eq;

	i = 0;
	eq = ft_strchr(key, '=');
	if (eq)
		len = eq - key;
	else
		len = ft_strlen(key);
	while (sh -> envp[i])
	{
		if (!ft_strncmp(sh -> envp[i], key, len)
			&& (sh -> envp[i][len] == '\0' || sh -> envp[i][len] == '='))
			return (&sh -> envp[i]);
		i++;
	}
	return (NULL);
}

char	*get_env_value(const char *key, char **envp)
{
	int		i;
	size_t	len;
	char	*tmp;

	i = 0;
	len = ft_strlen(key);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], key, len) == 0 && envp[i][len] == '=')
		{
			tmp = ft_strdup(&envp[i][len + 1]);
			return (tmp);
		}
		i++;
	}
	tmp = ft_strdup("");
	return (tmp);
}

void	update_lvl(t_shell *sh, char **shlvl)
{
	char	*num;
	char	*new_val;
	int		lvl;

	lvl = ft_atoi(ft_strchr(*shlvl, '=') + 1);
	lvl++;
	if (lvl < 0)
		lvl = 0;
	else if (lvl >= 1000)
	{
		printf("minishell: warning: ");
		printf("shell level (%d) too high, resetting to 1\n", lvl);
		lvl = 1;
	}
	num = ft_itoa(lvl);
	if (!num)
		clean_shell(sh, MALC_FAIL);
	new_val = ft_strjoin("SHLVL=", num);
	free(num);
	if (!new_val)
		clean_shell(sh, MALC_FAIL);
	update_key(shlvl, new_val);
	free(new_val);
}

void	update_shlvl(t_shell *sh, char **shlvl)
{
	char	**new_env;
	char	*value;
	bool	is_valid_lvl;

	shlvl = get_env_key(sh, "SHLVL");
	if (!shlvl || !ft_strchr(*shlvl, '='))
	{
		if (update_env(sh, "SHLVL=1", &new_env))
			clean_strs(new_env);
		return ;
	}
	value = ft_strchr(*shlvl, '=') + 1;
	is_valid_lvl = (*value != '\0');
	while (*value && is_valid_lvl)
	{
		if (!ft_isdigit(*value))
			is_valid_lvl = false;
		value++;
	}
	if (!is_valid_lvl)
		update_key(shlvl, "SHLVL=1");
	else
		update_lvl(sh, shlvl);
}
