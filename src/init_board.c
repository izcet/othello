/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:58:07 by irhett            #+#    #+#             */
/*   Updated: 2018/01/31 16:53:29 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void	init_board(t_turn *t, t_game *g)
{
	
	t->board[g_boardsize / 2][(g_boardsize / 2) - 1] = g->black->value;
	t->board[(g_boardsize / 2) - 1][g_boardsize / 2] = g->black->value;
	t->board[g_boardsize / 2][g_boardsize / 2] = g->white->value;
	t->board[(g_boardsize / 2) - 1][(g_boardsize / 2) - 1] = g->white->value;
	t->num_black += 2;
	t->num_white += 2;
	t->num_empty -= 4;
}
