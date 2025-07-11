/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 01:42:18 by felayan           #+#    #+#             */
/*   Updated: 2025/07/12 01:42:25 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_solution(int *board)
{
	int		i;
	char	num;

	i = 0;
	while (i < 10)
	{
		num = board[i] + '0';
		write(1, &num, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_valid_solution(int *board, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (board[i] == col
			|| (row - i) == (col - board[i])
			|| (row - i) == (board[i] - col))
			return (0);
		i++;
	}
	return (1);
}

void	solve_queens(int *board, int row, int *solutions)
{
	int	col;

	col = 0;
	if (row == 10)
	{
		print_solution(board);
		(*solutions)++;
		return ;
	}
	while (col < 10)
	{
		if (is_valid_solution(board, row, col))
		{
			board[row] = col;
			solve_queens(board, row + 1, solutions);
		}
		col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	solutions;
	int	board[10];

	solutions = 0;
	solve_queens(board, 0, &solutions);
	return (solutions);
}
// MAIN IS ONLY ADDED FOR TESTING, DO NOT PUSH IT TO PROJECT REPO AT CAMPUS
// #include <stdio.h>
// int main(void)
// {
// 	int sols = ft_ten_queens_puzzle();
// 	printf("Number of possible solutions: %d\n", sols);
// }
