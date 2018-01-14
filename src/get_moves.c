/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:27:38 by irhett            #+#    #+#             */
/*   Updated: 2018/01/13 23:28:03 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

t_movelist			*get_all_moves(t_turn *t, unsigned char boardsize)
{
	t_movelist		*list;
	unsigned char	row;
	unsigned char	col;
	unsigned int	id;
	unsigned int	flip;

	list = NULL;
	id = 0;
	row = 0;
	while (row < boardsize)
	{
		col = 0;
		while (col < boardsize)
		{
			if ((flip = is_valid_move(turn, boardsize, row, col)))
				list = movelist_add(list, make_move(g, row, col, id++, flip));
			col++;
		}
		row++;
	}
	return (list);
}

static void			place_move_data(t_turn *t, t_move *m)
{
	t->board[m->row][m->col] = m->id + 2;
}

static unsigned int	collision_number(t_turn *t, t_move *m, unsigned char dupes)
{
 // return the data without offset
}

t_movelist			*simplify_moves(t_turn *t, t_movelist *old,
									unsigned char size)
{
	t_movelist		*list;
	t_movelist		*curr;
	t_movelist		*temp;
	unsigned int	id_offset;
	unsigned char	board_dupes;
	unsigned int	collision;

	list = old;
	curr = old;
	id_offset = NULL;
	board_dupes = get_duplicates(t, size);
	if (board_dupes & 127)
	{
		place_move_data(t, old->data);
		old = old->next;
		while (old)
		{
			old->data->id -= id_offset;
			collision = collision_number(t, old->data, board_dupes);
			if (collision)
			{
				temp = list;
				while (list->data->id != collision - 2)
					temp = temp->next;
				temp->data->multiplier++;
				id_offset++;
				while (temp->next != old)
					temp = temp->next;
				temp->next = del_movelist(temp->next);
				old = temp;
			}
			else
				place_move_data(t, old);
			old = old->next;
		}

	}
	return (list);
}
