/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_add_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:13:23 by felayan           #+#    #+#             */
/*   Updated: 2025/09/29 05:00:01 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tk	get_opertype(const char *s)
{
	if (!ft_strncmp(s, "<<", 2))
		return (T_HEREDOC);
	if (!ft_strncmp(s, ">>", 2))
		return (T_APPEND);
	if (*s == '<')
		return (T_REDIR_IN);
	if (*s == '>')
		return (T_REDIR_OUT);
	if (*s == '|')
		return (T_PIPE);
	return (T_WORD);
}

t_tkns	*get_last_token(t_tkns *tokens)
{
	if (!tokens)
		return (NULL);
	while (tokens -> next)
		tokens = tokens -> next;
	return (tokens);
}

void	add_token(t_shell *sh, t_tk t_type, char *token, bool exp)
{
	t_tkns	*new;
	t_tkns	*last;

	last = NULL;
	new = malloc(sizeof(t_tkns));
	if (!new)
	{
		free(token);
		clean_shell(sh, MALC_FAIL);
	}
	new -> value = token;
	new -> type = t_type;
	new -> is_expand = exp;
	new -> next = NULL;
	if (!sh -> tokens)
		sh -> tokens = new;
	else
	{
		last = get_last_token(sh -> tokens);
		last -> next = new;
	}
}
