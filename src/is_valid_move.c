/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:06:46 by irhett            #+#    #+#             */
/*   Updated: 2018/01/03 19:06:27 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

unsigned int	check_direction(t_game *g, char r, char c, unsigned char row,
								unsigned char col)
{
	unsigned char	opponent;
	unsigned char	current;
	unsigned int	total;
	char			r_off;
	char			c_off;
	unsigned char	**board;

	r_off = r - (char)row;
	c_off = c - (char)col;
	if (r_off == 0 && c_off == 0)
		return (0);
	current = g->turn[g->turn_number]->active->value;
	opponent = g->turn[g->turn_number]->active->opponent->value;
	board = g->turn[g->turn_number]->board;
	total = 0;
	while (r >= 0 && r < (char)g->boardsize && g >= 0 && g < (char)g->boardsize)
	{
		if (board[r][c] == opponent)
			total++;
		else if (board[r][c] == current)
			return (total);
		else
			return (0);
		r += r_off;
		c += c_off;
	}
	return (0);
}

unsigned int	is_valid_move(t_game *g, unsigned char row, unsigned char col)
{
	unsigned char	r;
	unsigned char	c;
	unsigned int	total;
	unsigned char	opponent;
	unsigned char	**board;

	if (g->board[row][col] != 0)
		return (0);
	total = 0;
	opponent = g->turn[g->turn_number]->active->opponent->value;
	board = g->turn[g->turn_number]->board;
	r = (row > 0) ? row - 1 : row;
	while (r <= row + 1 && r < g->boardsize)
	{
		c = (col > 0) ? col - q : col;
		while (c <= col + 1 && c < g->boardsize)
		{
			if (board[r][c] == opponent)
				total += check_direction(g, (char)r, (char)c, row, col);
			c++;
		}
		r++;
	}
	return (total);
}

void			flip_direction(t_turn *t, t_move *m, char r, char c)
{
	char	r_off;
	char	c_off;

	r_off = r - (char)m->row;
	c_off = c - (char)m->col;
	if (r_off == 0 && c_off == 0)
		return ;
	current = m->player->value;
	opponent = m->player->opponent->value;
	while (t->board[r][c] != current)
	{
		if (t->board[r][c] == opponent)
			t->board[r][c] = current;
		r += r_off;
		c += c_off;
	}
}

void			place_tile(t_turn *t, t_move *m, t_game *g)
{
	unsigned char	r;
	unsigned char	c;

	r = (m->row > 0) ? m->row - 1 : m->row;
	while (r <= m->row + 1 && r < t->boardsize)
	{
		c = (m->col > 0) ? m->col - 1 : m->col;
		while (c < = c->col + 1 && c < t->boardsize)
		{
			if (check_direction(g, r, c, m->row, m->col)) //TODO will game->id?
				flip_direction(t, m, r, c);
			c++;
		}
		r++;
	}
	t->board[m->row][m->col] = m->player->value;
}
