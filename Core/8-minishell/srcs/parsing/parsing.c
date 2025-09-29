/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:09:57 by felayan           #+#    #+#             */
/*   Updated: 2025/09/29 05:45:35 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	append_cmd(t_shell *sh, t_cmd *new)
{
	t_cmd	*last;

	if (!sh -> cmds)
		sh -> cmds = new;
	else
	{
		last = get_last_cmd(sh -> cmds);
		last -> next = new;
	}
	sh -> cmd_count++;
}

static int	add_cmd(t_cmd *cmd, t_tkns **tokens, t_shell *sh)
{
	int	status;
	int	wrd_i;
	int	rdr_i;

	wrd_i = 0;
	rdr_i = 0;
	status = 0;
	while (*tokens && !is_pipe((*tokens)-> value))
	{
		if (is_redir((*tokens)-> value))
		{
			status = add_redir_cmd(cmd, tokens, &rdr_i, sh);
			if (status == MALC_FAIL)
				return (MALC_FAIL);
			else if (status == 130)
				return (130);
		}
		else
		{
			if (add_word_cmd(cmd, (*tokens)-> value, &wrd_i))
				return (MALC_FAIL);
		}
		(*tokens) = (*tokens)-> next;
	}
	return (SUCCESS);
}

static int	tokens_to_cmd(t_shell *sh, t_tkns *tokens)
{
	t_cmd	*new_cmd;
	int		status;

	if (!tokens)
		sh -> exit = 0;
	while (tokens)
	{
		new_cmd = init_cmd(sh, tokens);
		status = add_cmd(new_cmd, &tokens, sh);
		if (status == MALC_FAIL)
		{
			clean_cmds(new_cmd);
			clean_shell(sh, MALC_FAIL);
		}
		else if (status == 130)
		{
			clean_cmds(new_cmd);
			return (status);
		}
		append_cmd(sh, new_cmd);
		if (tokens && is_pipe(tokens -> value))
			tokens = tokens -> next;
	}
	return (SUCCESS);
}

static void	check_split_expansions(t_shell *sh)
{
	t_tkns	*curr;

	curr = sh -> tokens;
	while (curr)
	{
		if (curr -> is_expand && curr -> type == T_WORD
			&& ft_strchr(curr -> value, ' '))
			split_var(sh, curr);
		curr = curr -> next;
	}
}

int	parsing(t_shell *shell)
{
	if (tokenizer(shell) == SYNTAX_ERR)
	{
		clean_tokens(shell -> tokens);
		shell -> tokens = NULL;
		return (SYNTAX_ERR);
	}
	expander(shell);
	merge_tokens(shell);
	check_empty_expansions(shell);
	check_split_expansions(shell);
	if (tokens_to_cmd(shell, shell -> tokens) == 130)
	{
		clean_tokens(shell -> tokens);
		shell -> tokens = NULL;
		clean_cmds(shell -> cmds);
		shell -> cmds = NULL;
		return (130);
	}
	clean_tokens(shell -> tokens);
	shell -> tokens = NULL;
	return (SUCCESS);
}
