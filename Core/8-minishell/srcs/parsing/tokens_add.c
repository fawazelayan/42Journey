/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:09:34 by felayan           #+#    #+#             */
/*   Updated: 2025/09/29 04:49:29 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_single_quotes(t_shell *sh, int *indx)
{
	int		sub_len;
	int		start;
	char	*sub;

	(*indx)++;
	sub = NULL;
	sub_len = 0;
	start = *indx;
	while (sh -> cmd_line[*indx] && sh -> cmd_line[*indx] != '\'')
	{
		(*indx)++;
		sub_len++;
	}
	sub = ft_substr(sh -> cmd_line, start, sub_len);
	if (!sub)
		clean_shell(sh, MALC_FAIL);
	if (sh -> cmd_line[*indx] == '\'')
		(*indx)++;
	add_token(sh, T_SINGLE, sub, false);
	sh -> last = get_last_token(sh -> tokens);
	sh -> last -> is_not_mergable = is_not_mergable(sh -> cmd_line[*indx]);
}

void	add_double_quotes(t_shell *sh, int *indx)
{
	int		sub_len;
	int		start;
	char	*sub;
	bool	is_expandable;

	(*indx)++;
	sub = NULL;
	start = *indx;
	sub_len = 0;
	is_expandable = false;
	while (sh -> cmd_line[*indx] && sh -> cmd_line[*indx] != '\"')
	{
		if (sh -> cmd_line[*indx] == '$' && is_var(sh -> cmd_line[*indx + 1]))
			is_expandable = true;
		(*indx)++;
		sub_len++;
	}
	sub = ft_substr(sh -> cmd_line, start, sub_len);
	if (!sub)
		clean_shell(sh, MALC_FAIL);
	add_token(sh, T_DOUBLE, sub, is_expandable);
	if (sh -> cmd_line[*indx] == '\"')
		(*indx)++;
	sh -> last = get_last_token(sh -> tokens);
	sh -> last -> is_not_mergable = is_not_mergable(sh -> cmd_line[*indx]);
}

void	add_operator(t_shell *sh, int *indx)
{
	char	*sub;
	t_tk	oper_t;

	oper_t = get_opertype(&sh -> cmd_line[*indx]);
	sub = NULL;
	if (oper_t == T_REDIR_IN || oper_t == T_REDIR_OUT || oper_t == T_PIPE)
	{
		sub = ft_substr(sh -> cmd_line, *indx, 1);
		(*indx)++;
	}
	else if (oper_t == T_APPEND || oper_t == T_HEREDOC)
	{
		sub = ft_substr(sh -> cmd_line, *indx, 2);
		*indx += 2;
	}
	if (!sub)
		clean_shell(sh, MALC_FAIL);
	add_token(sh, oper_t, sub, false);
	sh -> last = get_last_token(sh -> tokens);
	sh -> last -> is_not_mergable = true;
}

void	add_word(t_shell *sh, int *indx)
{
	int		sub_len;
	int		start;
	char	*sub;
	bool	is_expandable;

	sub = NULL;
	start = *indx;
	sub_len = 0;
	is_expandable = false;
	while (sh -> cmd_line[*indx] && is_word(sh -> cmd_line[*indx]))
	{
		if (sh -> cmd_line[*indx] == '$' && is_var(sh -> cmd_line[*indx + 1]))
			is_expandable = true;
		(*indx)++;
		sub_len++;
	}
	sub = ft_substr(sh -> cmd_line, start, sub_len);
	if (!sub)
		clean_shell(sh, MALC_FAIL);
	add_token(sh, T_WORD, sub, is_expandable);
	sh -> last = get_last_token(sh -> tokens);
	sh -> last -> is_not_mergable = is_not_mergable(sh -> cmd_line[*indx]);
}
