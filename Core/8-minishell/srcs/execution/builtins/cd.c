/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:22:39 by moaljazz          #+#    #+#             */
/*   Updated: 2025/09/28 20:56:43 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_dir(char *dir, t_shell *sh)
{
	if (chdir(dir))
	{
		perror("cd");
		sh -> exit = 1;
	}
	else
		sh -> exit = 0;
}

int	cd_cmd(char **av, t_shell *sh)
{
	char	*home;

	if (!av[1])
	{
		home = get_env_value("HOME", sh -> envp);
		if (!home)
			sh -> exit = MALC_FAIL;
		else if (home[0] == '\0')
		{
			ft_putstr_fd("cd: HOME not set\n", 2);
			sh -> exit = 1;
		}
		else
			change_dir(home, sh);
		free(home);
	}
	else if (av[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		sh -> exit = 1;
	}
	else
		change_dir(av[1], sh);
	return (SUCCESS);
}
