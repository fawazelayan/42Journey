/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:09:28 by felayan           #+#    #+#             */
/*   Updated: 2025/09/29 04:47:28 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	create_tokens(int indx, t_shell *sh)
{
	while (sh -> cmd_line[indx])
	{
		if (sh -> cmd_line[indx] == '\'')
			add_single_quotes(sh, &indx);
		else if (sh -> cmd_line[indx] == '\"')
			add_double_quotes(sh, &indx);
		else if (is_oper(sh -> cmd_line[indx]))
			add_operator(sh, &indx);
		else if (is_word(sh -> cmd_line[indx]))
			add_word(sh, &indx);
		else
			indx++;
	}
}

int	tokenizer(t_shell *shell)
{
	int		i;
	bool	is_closed;

	i = skip_whitesp(shell -> cmd_line);
	is_closed = is_closed_quotes(shell -> cmd_line, i);
	if (is_closed)
		create_tokens(i, shell);
	if (syntax_check(shell -> tokens, !is_closed))
	{
		shell -> exit = 2;
		return (SYNTAX_ERR);
	}
	return (SUCCESS);
}
