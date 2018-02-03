/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:45:32 by irhett            #+#    #+#             */
/*   Updated: 2018/02/02 17:57:00 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		print_board(unsigned char **board)
{
	int		row;
	int		col;

	row = 0;
	while (row < g_boardsize)
	{
		col = 0;
		while (col < g_boardsize)
		{
			if (board[row][col] == 0)
				ft_putchar('-');
			else if (board[row][col] == 1)
				ft_putchar('X');
			else if (board[row][col] == 2)
				ft_putchar('O');
			else
				ft_putchar('a' - 3 + board[row][col]);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
	ft_putchar('\n');
}
