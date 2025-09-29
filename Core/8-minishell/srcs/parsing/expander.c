/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:10:09 by felayan           #+#    #+#             */
/*   Updated: 2025/09/29 06:07:11 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	disable_expand(t_tkns *curr)
{
	while (curr && !curr -> is_not_mergable)
	{
		curr -> is_expand = false;
		curr = curr -> next;
	}
	if (curr)
		curr -> is_expand = false;
}

static char	*get_var(const char *var, int *loc)
{
	int	start;

	start = *loc;
	if (ft_isdigit(var[*loc]))
	{
		(*loc)++;
		return (NULL);
	}
	while (var[*loc] && (ft_isalnum(var[*loc]) || var[*loc] == '_'))
		(*loc)++;
	return (ft_substr(var, start, *loc - start));
}

int	expand_var(t_shell *sh, const char *tk)
{
	int	i;

	i = 0;
	while (tk[i])
	{
		if (tk[i] != '$' || !is_var(tk[i + 1]))
		{
			sh -> expand = append_char(sh -> expand, tk[i++]);
			if (!sh -> expand)
				return (MALC_FAIL);
		}
		else if (tk[++i] == '?')
		{
			if (create_var(sh, tk[i], ft_itoa(sh-> exit), true) == MALC_FAIL)
				return (MALC_FAIL);
			i++;
		}
		else
		{
			if (create_var(sh, tk[i], get_var(tk, &i), false) == MALC_FAIL)
				return (MALC_FAIL);
		}
	}
	return (SUCCESS);
}

void	expander(t_shell *sh)
{
	t_tkns	*current;

	current = sh -> tokens;
	while (current)
	{
		if (current -> type == T_HEREDOC)
			disable_expand(current -> next);
		if (current -> is_expand)
		{
			sh -> expand = ft_strdup("");
			if (!sh -> expand || expand_var(sh, current -> value))
			{
				free(sh -> expand);
				clean_shell(sh, MALC_FAIL);
			}
			free(current -> value);
			current -> value = ft_strdup(sh -> expand);
			if (!current -> value)
				clean_shell(sh, MALC_FAIL);
			free(sh -> expand);
			sh -> expand = NULL;
		}
		current = current -> next;
	}
}
