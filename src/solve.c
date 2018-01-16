/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 17:05:36 by irhett            #+#    #+#             */
/*   Updated: 2018/01/15 17:15:59 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		solve(t_data *d, t_game *g)
{
	if (g->turn_curr + 1 >= g->turn_size)
		extend_game(g);
	if (game_over(g))
	{
		g->turn_last = g->turn_curr;
		record_stats(g, d);
		while (g->turn_curr > 0 && g->turn[g->turn_curr]->move == NULL)
		{
			g->turn[g->turn_curr]->done = 1;
			g->turn_curr--;
			del_move(movelist_pop(&(g->turn[g->turn_curr]->move)));
		}
		if (g->turn_curr == 0)
			g->turn[0]->done = 1;
	}
	else
	{
		take_turn(g->turn[g->turn_curr], g->turn[g->turn_curr + 1]);
		g->turn_curr++;
	}
}

void		start_solve(t_data *d)
{
	t_game	*g;
	if (d->verbosity)
	{
		printf("Solving for a board size %ix%i\n", d->boardsize, d->boardsize);
		// TODO iplement ft_printf_fd
	}
	if (d->verbosity >= 42) // I shouldn't do anything above 3
		ft_putendl("This output is gonna be hella verbose!");
	printf("solving here...\n");
	d->game = new_game(d->boardsize);
	g = d->game;
	init_board(g->turn[0], g->size, g->black, g->white);
	while (g->turn[0]->done == 0) // TODO is done necessary or just t->move
		solve(d, g);
}
