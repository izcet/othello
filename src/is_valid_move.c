/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:06:46 by irhett            #+#    #+#             */
/*   Updated: 2018/02/02 19:04:01 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

unsigned int	check_direction(t_turn *t, char r, char c, unsigned char row,
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
	current = t->active->value;
	opponent = t->active->opponent->value;
	board = t->board;
	total = 0;
	while (r >= 0 && r < (char)g_boardsize && c >= 0 && c < (char)g_boardsize)
	{
		if (board[(int)r][(int)c] == opponent)
			total++;
		else if (board[(int)r][(int)c] == current)
			return (total);
		else
			return (0);
		r += r_off;
		c += c_off;
	}
	return (0);
}

unsigned int	check_direction2(t_turn *t, char r, char c, unsigned char row,
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
	opponent = t->active->value;
	current = t->active->opponent->value;
	board = t->board;
	total = 0;
	while (r >= 0 && r < (char)g_boardsize && c >= 0 && c < (char)g_boardsize)
	{
		if (board[(int)r][(int)c] == opponent)
			total++;
		else if (board[(int)r][(int)c] == current)
			return (total);
		else
			return (0);
		r += r_off;
		c += c_off;
	}
	return (0);
}

unsigned int	is_valid_move(t_turn *t, unsigned char row, unsigned char col)
{
	unsigned char	r;
	unsigned char	c;
	unsigned int	total;
	unsigned char	opponent;
	unsigned char	**board;
	
	board = t->board;
	if (board[row][col] != 0)
		return (0);
	total = 0;
	opponent = t->active->opponent->value;
	r = (row > 0) ? row - 1 : row;
	while (r <= row + 1 && r < g_boardsize)
	{
		c = (col > 0) ? col - 1 : col;
		while (c <= col + 1 && c < g_boardsize)
		{
			if (board[(int)r][(int)c] == opponent)
				total += check_direction(t, (char)r, (char)c, row, col);
			c++;
		}
		r++;
	}
	return (total);
}

void			flip_direction(t_turn *t, t_move *m, char r, char c)
{
	char			r_off;
	char			c_off;
	unsigned char	current;
	unsigned char	opponent;

	r_off = r - (char)m->row;
	c_off = c - (char)m->col;
	if (r_off == 0 && c_off == 0)
		return ;
	current = m->player->value;
	opponent = m->player->opponent->value;
	while (t->board[(int)r][(int)c] != current)
	{
		//if (t->board[(int)r][(int)c] == opponent)
			t->board[(int)r][(int)c] = current;
		r += r_off;
		c += c_off;
	}
}

void			place_tile(t_turn *t, t_move *m)
{
	unsigned char	r;
	unsigned char	c;

	r = (m->row > 0) ? m->row - 1 : 0;
	while (r <= m->row + 1 && r < g_boardsize)
	{
		c = (m->col > 0) ? m->col - 1 : 0;
		while (c <= m->col + 1 && c < g_boardsize)
		{
			if (check_direction2(t, r, c, m->row, m->col))
			{
				printf("yep\n");
				flip_direction(t, m, r, c);
			}
			else
				printf("nope\n");
			c++;
		}
		r++;
		printf("\n");
	}
	t->board[m->row][m->col] = m->player->value;
	printf("\n");
}
