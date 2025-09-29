/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:13:19 by felayan           #+#    #+#             */
/*   Updated: 2025/09/25 21:02:27 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_oper(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	skip_whitesp(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && ((s[i] >= 9 && s[i] <= 13) || s[i] == 32))
		i++;
	return (i);
}

bool	is_word(char token)
{
	if (is_oper(token)
		|| token == '\'' || token == '\"'
		|| token == ' ' || (token >= 9 && token <= 13))
		return (false);
	return (true);
}

bool	is_pipe(const char *token)
{
	return (!ft_strncmp(token, "|", 1));
}

bool	is_redir(const char *token)
{
	if (!ft_strncmp(token, ">>", 2))
		return (true);
	if (!ft_strncmp(token, "<<", 2))
		return (true);
	if (!ft_strncmp(token, ">", 1))
		return (true);
	if (!ft_strncmp(token, "<", 1))
		return (true);
	return (false);
}
