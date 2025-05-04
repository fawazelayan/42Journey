/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:11:56 by felayan           #+#    #+#             */
/*   Updated: 2025/05/02 20:12:01 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc == 1)
		return (EXIT_FAILURE);
	if (validate_arguments(argc - 1, &argv[1]))
		error_output();
	a = init_stack();
	if (!a)
		clean_and_exit(&a, EXIT_FAILURE);
	if (fill_stack(a, argc - 1, &argv[1]))
		clean_and_exit(&a, EXIT_FAILURE);
	sort_stack(a);
	clean_and_exit(&a, EXIT_SUCCESS);
}
