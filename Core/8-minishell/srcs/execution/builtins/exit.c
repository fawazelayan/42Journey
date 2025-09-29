/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:24:56 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/09/25 20:29:05 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_atoi_exit(const char *str, int *sta, bool *valid)
{
	int		sign;
	size_t	i;

	sign = 1;
	i = skip_whitesp(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		(*sta) = ((*sta) * 10) + (str[i] - '0');
		i++;
	}
	if (i != ft_strlen(str))
		i += skip_whitesp(&str[i]);
	if (i != ft_strlen(str))
	{
		(*sta) = 2;
		(*valid) = false;
		return ;
	}
	(*sta) *= sign;
}

static void	exit_status(t_shell *shell, t_cmd *cmd, bool valid)
{
	if (shell -> cmd_count == 1)
		ft_putstr_fd("exit\n", 2);
	if (shell -> exit == 2 && !valid && cmd -> args[1])
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd -> args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
	}
	else if (cmd -> args[1] && cmd -> args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		shell -> exit = 1;
		return ;
	}
	clean_shell(shell, shell -> exit);
}

void	exit_cmd(t_cmd *cmd, t_shell *shell)
{
	bool	valid;

	valid = true;
	if (shell -> cmd_count == 1 && !shell -> cmds -> args[1])
		exit_status(shell, cmd, valid);
	if (cmd -> args[1])
		ft_atoi_exit(cmd -> args[1], &shell -> exit, &valid);
	exit_status(shell, cmd, valid);
}
