/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:49:48 by felayan           #+#    #+#             */
/*   Updated: 2024/07/24 14:04:56 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first(int col, char line[200][200])
{
	int	j;

	line[0][0] = 'A';
	line[0][col - 1] = 'A';
	j = 0;
	while (j < col)
	{
		if (j > 0 && j < col - 1)
			line[0][j] = 'B';
		ft_putchar(line[0][j]);
		j++;
	}
}

void	middle(int col, int i, char line[200][200])
{
	int	j;

	j = 0;
	while (j < col)
	{
		line[i][j] = 'B';
		if (j != 0 && j != col - 1)
			line[i][j] = ' ';
		ft_putchar(line[i][j]);
		j++;
	}
}

void	last(int col, int i, char line[200][200])
{
	int	j;

	line[i][0] = 'C';
	line[i][col - 1] = 'C';
	j = 0;
	while (j < col)
	{
		if (j != 0 && j != col - 1)
			line[i][j] = 'B';
		ft_putchar(line[i][j]);
		j++;
	}
}

void	rush(int col, int row)
{
	char	line[200][200];
	int		i;

	i = 0;
	if (col >= 1 && row >= 1)
	{
		while (i < row)
		{
			if (i == 0)
				first(col, line);
			else if (i == row - 1)
				last(col, i, line);
			else
				middle(col, i, line);
			i++;
			ft_putchar('\n');
		}
	}
}
