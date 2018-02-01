/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 17:05:36 by irhett            #+#    #+#             */
/*   Updated: 2018/01/31 18:59:20 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

#define CURR g->turn_curr

void		solve(t_data *d, t_game *g)
{
	if (CURR + 1 >= g->turn_size)
		extend_game(g);
	if (is_game_over(g))
	{
		g->turn_last = CURR;
		handle_stats(g, d);
		while (CURR >= 0 && g->turn[CURR]->move == NULL)
		{
			g->turn[CURR]->done = 1;
			CURR--;
			if (CURR >= 0)
				del_move(movelist_pop(&(g->turn[CURR]->move)));
		}
	}
	else
	{
		take_turn(g->turn[CURR], g->turn[CURR + 1]);
		CURR++;
	}
}

void		start_solve(t_data *d)
{
	t_game	*g;
	if (d->verbosity)
	{
		printf("Solving for a board size %ix%i\n", g_boardsize, g_boardsize);
		// TODO iplement ft_printf_fd
	}
	if (d->verbosity >= 42) // I shouldn't do anything above 3
		ft_putendl("This output is gonna be hella verbose!");
	printf("solving here...\n");
	d->game = new_game();
	g = d->game;
	init_board(g->turn[0], g);
	while (g->turn[0]->done == 0) // TODO is done necessary or just t->move
		solve(d, g);
}
