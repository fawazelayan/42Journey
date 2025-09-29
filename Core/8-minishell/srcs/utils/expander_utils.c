/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:12:40 by felayan           #+#    #+#             */
/*   Updated: 2025/09/25 23:01:36 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_var(char var)
{
	if (ft_isalnum(var) || var == '_' || var == '?')
		return (true);
	return (false);
}

char	*append_char(char *s, char c)
{
	char	*appended;
	int		len;

	if (!s)
	{
		appended = malloc(2);
		if (!appended)
			return (NULL);
		appended[0] = c;
		appended[1] = '\0';
		return (appended);
	}
	len = ft_strlen(s);
	appended = malloc(len + 2);
	if (!appended)
	{
		free(s);
		return (NULL);
	}
	ft_memcpy(appended, s, len);
	appended[len++] = c;
	appended[len] = '\0';
	free(s);
	return (appended);
}

char	*append_str(char **env, char *s1, const char *s2, bool is_special)
{
	char	*val;
	char	*appended;

	val = NULL;
	appended = NULL;
	if (is_special)
		appended = ft_strjoin(s1, s2);
	else
	{
		val = get_env_value(s2, env);
		if (!val)
		{
			free(s1);
			return (NULL);
		}
		appended = ft_strjoin(s1, val);
		free(val);
	}
	free(s1);
	return (appended);
}

int	append_arg(t_shell *sh, char c)
{
	int		num;
	char	*tmp;

	num = c - '0';
	if (num >= sh -> ac)
		return (1);
	tmp = sh -> expand;
	if (sh -> av[num])
		sh -> expand = ft_strjoin(tmp, sh -> av[num]);
	free(tmp);
	if (!sh -> expand)
		return (MALC_FAIL);
	return (SUCCESS);
}

int	create_var(t_shell *sh, char c, char *key, bool is_special)
{
	int	st;

	if (!key && !ft_isdigit(c))
		return (MALC_FAIL);
	if (ft_isdigit(c))
	{
		st = append_arg(sh, c);
		if (!st)
		{
			free(key);
			return (SUCCESS);
		}
		else if (st == MALC_FAIL)
		{
			free(key);
			return (MALC_FAIL);
		}
		return (1);
	}
	sh -> expand = append_str(sh -> envp, sh -> expand, key, is_special);
	free(key);
	if (!sh -> expand)
		return (MALC_FAIL);
	return (SUCCESS);
}
