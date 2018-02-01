/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:26:55 by irhett            #+#    #+#             */
/*   Updated: 2018/01/31 17:29:32 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

int		is_game_over(t_game *g)
{
	int		row;
	int		col;

	if (g->turn[g->turn_curr]->move)
		return (0);
	if (g->turn[g->turn_curr]->num_empty == 0)
		return (1);
	copy_board(g->turn[g->turn_curr], g->turn[g->turn_curr + 1]);
	row = 0;
	while (row < g_boardsize)
	{
		col = 0;
		while (col < g_boardsize)
		{
			if (is_valid_move(g->turn[g->turn_curr + 1], row, col))
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}
