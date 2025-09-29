/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 01:37:10 by felayan           #+#    #+#             */
/*   Updated: 2025/09/28 23:45:43 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	partition(char **arr, int low, int high)
{
	int		i;
	int		j;
	char	*pivot;

	j = low;
	i = low - 1;
	pivot = arr[high];
	while (j < high)
	{
		if (ft_strcmp(arr[j], pivot) < 0)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	sort_env(char **arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		sort_env(arr, low, pi - 1);
		sort_env(arr, pi + 1, high);
	}
}

static int	print_exp(char **env)
{
	int		i;
	char	*eq;
	char	**sorted_env;

	i = 0;
	sorted_env = malloc(sizeof(char *) * (count_env_entries(env) + 1));
	if (copy_env(sorted_env, env))
	{
		clean_strs(sorted_env);
		return (MALC_FAIL);
	}
	sort_env(sorted_env, 0, count_env_entries(sorted_env) - 1);
	while (sorted_env[i])
	{
		eq = ft_strchr(sorted_env[i], '=');
		if (eq)
			printf("declare -x %.*s=\"%s\"\n",
				(int)(eq - sorted_env[i]), sorted_env[i], eq + 1);
		else
			printf("declare -x %s\n", sorted_env[i]);
		i++;
	}
	clean_strs(sorted_env);
	return (SUCCESS);
}

static void	export_add(char *arg, t_shell *sh)
{
	if (!is_valid_key(arg))
	{
		sh -> exit = 1;
		ft_putstr_fd("minishell: export: `", STDERR_FILENO);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
	else
	{
		set_var(sh, arg);
		sh -> exit = 0;
	}
}

int	export_cmd(char **args, t_shell *shell)
{
	int	i;

	i = 1;
	if (!args[1])
	{
		shell -> exit = 0;
		if (print_exp(shell -> envp))
			clean_shell(shell, MALC_FAIL);
	}
	while (args[i])
	{
		export_add(args[i], shell);
		i++;
	}
	return (SUCCESS);
}
