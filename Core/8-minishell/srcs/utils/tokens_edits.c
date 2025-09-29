/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_edits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 23:31:55 by felayan           #+#    #+#             */
/*   Updated: 2025/09/29 05:01:02 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_not_mergable(char c)
{
	if (c == 32 || (c >= 9 && c <= 13) || is_oper(c) || !c)
		return (true);
	return (false);
}

void	merge_tokens(t_shell *sh)
{
	char	*new_val;
	t_tkns	*curr;
	t_tkns	*to_free;

	curr = sh -> tokens;
	while (curr)
	{
		if (!curr -> is_not_mergable)
		{
			to_free = curr -> next;
			new_val = ft_strjoin(curr -> value, to_free -> value);
			if (!new_val)
				clean_shell(sh, MALC_FAIL);
			free(curr -> value);
			curr -> value = new_val;
			curr -> is_not_mergable = to_free -> is_not_mergable;
			curr -> next = to_free -> next;
			free(to_free -> value);
			free(to_free);
			continue ;
		}
		else
			curr = curr -> next;
	}
}

void	check_empty_expansions(t_shell *sh)
{
	t_tkns	*to_free;
	t_tkns	*curr;
	t_tkns	*prev;

	prev = NULL;
	curr = sh -> tokens;
	while (curr)
	{
		if (curr -> is_expand && curr -> type == T_WORD && !curr -> value[0])
		{
			to_free = curr;
			if (prev)
				prev -> next = curr -> next;
			else
				sh -> tokens = curr -> next;
			curr = curr -> next;
			free(to_free -> value);
			free(to_free);
		}
		else
		{
			prev = curr;
			curr = curr -> next;
		}
	}
}

t_tkns	*create_token(char *val)
{
	t_tkns	*new;

	new = malloc(sizeof(t_tkns));
	if (!new)
		return (NULL);
	ft_bzero(new, sizeof(t_tkns));
	new -> value = ft_strdup(val);
	if (!new -> value)
	{
		free(new);
		return (NULL);
	}
	new -> type = T_WORD;
	return (new);
}

void	split_var(t_shell *sh, t_tkns *curr)
{
	int		i;
	char	**splits;
	t_tkns	*tmp;
	t_tkns	*org_next;

	i = 0;
	tmp = curr;
	org_next = tmp -> next;
	splits = ft_split(curr -> value, ' ');
	if (!splits)
		clean_shell(sh, MALC_FAIL);
	free(curr -> value);
	curr -> value = ft_strdup(splits[0]);
	if (!curr -> value)
	{
		clean_strs(splits);
		clean_shell(sh, MALC_FAIL);
	}
	while (splits[++i])
	{
		tmp -> next = create_token(splits[i]);
		tmp = tmp -> next;
	}
	tmp -> next = org_next;
	clean_strs(splits);
}
