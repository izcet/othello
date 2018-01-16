/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:58:07 by irhett            #+#    #+#             */
/*   Updated: 2018/01/15 17:06:17 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void	init_board(t_turn *t, unsigned char size, t_player *b, t_player *w)
{
	
	t->board[size / 2][(size / 2) - 1] = b->value;
	t->board[(size / 2) - 1][size / 2] = b->value;
	t->board[size / 2][size / 2] = w->value;
	t->board[(size / 2) - 1][(size / 2) - 1] = w->value;
	t->num_black += 2;
	t->num_white += 2;
	t->num_empty -= 4;
}
