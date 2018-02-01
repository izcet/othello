/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:27:38 by irhett            #+#    #+#             */
/*   Updated: 2018/01/31 18:58:54 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

t_movelist			*get_all_moves(t_turn *t)
{
	t_movelist		*list;
	t_move			*m;
	unsigned char	row;
	unsigned char	col;
	unsigned int	id;
	unsigned int	flip;

	list = NULL;
	id = 0;
	row = 0;
	while (row < g_boardsize)
	{
		col = 0;
		while (col < g_boardsize)
		{
			if ((flip = is_valid_move(t, row, col)))
			{
				m = new_move(row, col, id++, flip, t->active);
				list = movelist_add(list, m);
			}
			col++;
		}
		row++;
	}
	return (list);
}

static void			place_move_data(t_turn *t, t_move *m)
{
	t->board[m->row][m->col] = m->id + 3;
}

static unsigned int	get_space_at(t_turn *t, t_move *m, unsigned char rots)
{
	unsigned int	col;
	unsigned int	row;

	col = (rots & 1 ? m->col : g_boardsize - 1 - m->col);
	row = (rots & 2 ? m->row : g_boardsize - 1 - m->row);
	if (rots & 4)
		return (t->board[col][row]);
	return (t->board[row][col]);
}

static unsigned int	collision_number(t_turn *t, t_move *m, unsigned char dupes)
{
	unsigned char	curr;
	unsigned char	mask;
	unsigned int	collision;

	curr = 0;
	mask = 1;
	while (mask < 128)
	{
		if (mask & dupes)
		{
			collision = get_space_at(t, m, curr);
			if (collision > 2)
				return (collision);
		}
		curr++;
		mask <<= 1;
	}
	return (0);
}

t_movelist			*simplify_moves(t_turn *t, t_movelist *old)
{
	t_movelist		*list;
	t_movelist		*curr;
	t_movelist		*temp;
	unsigned int	id_offset;
	unsigned char	board_dupes;
	unsigned int	collision;

	list = old;
	curr = old;
	id_offset = 0;
	board_dupes = get_duplicates(t);
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
				while (list->data->id != collision - 3)
					temp = temp->next;
				temp->data->multiplier++;
				id_offset++;
				while (temp->next != old)
					temp = temp->next;
				temp->next = del_movelist(temp->next);
				old = temp;
			}
			else
				place_move_data(t, old->data);
			old = old->next;
		}
	}
	return (list);
}
