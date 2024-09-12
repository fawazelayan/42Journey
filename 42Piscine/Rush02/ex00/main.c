/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:18:03 by felayan           #+#    #+#             */
/*   Updated: 2024/09/11 22:50:25 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
//hi
int	get_two_digit(long long nbr)
{
	if (nbr >= 90)
		return (90);
	else if (nbr >= 80)
		return (80);
	else if (nbr >= 70)
		return (70);
	else if (nbr >= 60)
		return (60);
	else if (nbr >= 50)
		return (50);
	else if (nbr >= 40)
		return (40);
	else if (nbr >= 30)
		return (30);
	else if (nbr >= 20)
		return (20);
	else if (nbr <= 20)
		return (nbr);
	return (0);
}

long long int	get_decimal_classes(long long int nbr)
{
	if (nbr >= 1e15)
		return (1e15);
	else if (nbr >= 1e12)
		return (1e12);
	else if (nbr >= 1e9)
		return (1e9);
	else if (nbr >= 1e6)
		return (1e6);
	else if (nbr >= 1e3)
		return (1e3);
	else if (nbr >= 1e2)
		return (1e2);
	return (get_two_digit(nbr));
}

void	ft_print(long long int n, t_list *list, int *space)
{
	int					i;
	long long int		decimal_class;

	i = 0;
	decimal_class = get_decimal_classes(n);
	if (decimal_class >= 100)
		ft_print(n / decimal_class, list, space);
	if (*space == 0)
		write(1, " ", 1);
	*space = 0;
	while (list[i].nbr != decimal_class)
		i++;
	ft_putstr(list[i].number_name);
	if (decimal_class != 0 && n % decimal_class != 0)
		ft_print(n % decimal_class, list, space);
}

int	check_error(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			ft_putstr("Error found float number\n");
			return (-1);
		}
		i++;
	}
	if (ft_atoi(str) < 0)
	{
		ft_putstr("Error number less than 0\n");
		return (-1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*list;
	int		space;

	space = 1;
	if (argc == 2)
	{
		if (check_error(argv[1]) == -1)
			return (-1);
		list = create_list("numbers.dict");
		ft_print(ft_atoi(argv[1]), list, &space);
		ft_putchar('\n');
	}
	return (0);
}
