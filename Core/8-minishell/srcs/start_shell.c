/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:17:22 by felayan           #+#    #+#             */
/*   Updated: 2025/09/28 18:58:13 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_shell_banner(char **envp)
{
	char	*clear[2];
	pid_t	pid;

	clear[0] = "/usr/bin/clear";
	clear[1] = NULL;
	pid = fork();
	if (!pid)
	{
		execve(clear[0], clear, envp);
		perror("Banner execve failed");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
		printf(BBLU"\n\t███████╗██╗  ██╗███████╗██╗     ██╗     ██╗  ██╗\n");
		printf("\t██╔════╝██║  ██║██╔════╝██║     ██║     ╚██╗██╔╝\n");
		printf("\t███████╗███████║█████╗  ██║     ██║      ╚███╔╝ \n");
		printf("\t╚════██║██╔══██║██╔══╝  ██║     ██║      ██╔██╗ \n");
		printf("\t███████║██║  ██║███████╗███████╗███████╗██╔╝ ██╗\n");
		printf("\t╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝\n"RST"\n");
	}
	else
		perror("fork banner");
}

int	copy_env(char **dest, char **envp)
{
	int	i;

	i = 0;
	if (!dest)
		return (MALC_FAIL);
	while (envp[i])
	{
		dest[i] = ft_strdup(envp[i]);
		if (!dest[i])
			return (MALC_FAIL);
		i++;
	}
	dest[i] = NULL;
	return (SUCCESS);
}

static void	init_env(t_shell *sh, char **env)
{
	char	**shlvl;

	shlvl = NULL;
	sh -> envp = malloc(sizeof(char *) * (count_env_entries(env) + 1));
	if (copy_env(sh -> envp, env))
		clean_shell(sh, MALC_FAIL);
	update_shlvl(sh, shlvl);
}

static void	init_shell(t_shell *sh, int argc, char **argv, char **envp)
{
	print_shell_banner(envp);
	ft_bzero(sh, sizeof(t_shell));
	sh -> ac = argc;
	sh -> av = argv;
	init_env(sh, envp);
}

void	start_shell(t_shell *shell, int argc, char **argv, char **envp)
{
	init_shell(shell, argc, argv, envp);
	while (42)
	{
		shell -> cmd_count = 0;
		shell -> last_cmd_pid = -1;
		prompt_signals();
		if (!isatty(STDIN_FILENO))
			dup2(STDERR_FILENO, STDIN_FILENO);
		shell -> cmd_line = readline("\033[31mSHELLX 🔥 > \002"RST);
		if (g_sig)
			shell -> exit = g_sig;
		g_sig = 0;
		if (!shell -> cmd_line)
			break ;
		if (!is_empty(shell -> cmd_line))
		{
			add_history(shell -> cmd_line);
			if (!parsing(shell))
				execution(shell);
		}
		free(shell -> cmd_line);
	}
	printf("exit\n");
	close(0);
	clean_shell(shell, shell -> exit);
}
