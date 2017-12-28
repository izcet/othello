/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:43 by irhett            #+#    #+#             */
/*   Updated: 2017/12/27 19:41:04 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		del_game(t_game *g)
{
	unsigned int	i;

	if (g)
	{
		if (g->turn)
		{
			i = 0;
			while (i < g->maximum)
				del_turn(g->turn[i]);
			free(g->turn);
		}
		if (g->board)
		{
			i = 0;
			while (i < g->maximum)
				del_board(g->board[i]);
			free(g->board);
		}
		free(g);
	}
}

t_game	*new_game(unsigned char size)
{
	t_game			*g;
	unsigned int	i;

	g = (t_game *)malloc(sizeof(t_game));
	if (!g)
		return (game_error(NULL, "new_game malloc() of g"));
	g->size = size;
	g->maximum = ((size * size) * 1.5);
	g->turn_number = 0;
	g->board = (t_board **)malloc(sizeof(t_board *) * maximum);
	if (!g->board)
		return (game_error(g, "new_game malloc() of g->board"));
	g->turn = (t_turn **)malloc(sizeof(t_turn *) * maximum);
	if (!g->turn)
	{
		del_game(g);
		return (game_error(NULL, "new_game malloc() of g->turn"));
	}
	i = 0;
	while (i < maximum)
	{
		g->board[i] = new_board(size);
		if (!g->board[i])
		{
			del_game(g);
			return (game_error(NULL, "new_game malloc() of g->board[i]"));
		}
		g->turn[i] = new_turn(/*TODO*/);
		if (!g->turn[i])
		{
			del_game(g);
			return (game_error(NULL, "new_game malloc() of g->turn[i]"));
		}
		g->board[i]->turn = g->turn[i];
		g->turn[i]->board = g->board[i];
		i++;
	}
	return (g);
}
