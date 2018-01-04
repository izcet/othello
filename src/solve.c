/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 17:05:36 by irhett            #+#    #+#             */
/*   Updated: 2018/01/03 20:26:44 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		solve(t_data *d, t_game *g)
{
	if (g->turn_curr + 1 >= g->turn_size)
		extend_game(g);
	if (g->turn[g->turn_curr]->done)
	{
		g->turn_curr--;
		return ;
	}
	if (is_game_over(g))
	{
		g->turn_last = g->turn_curr;
		record_stats(g, d);
		g->turn[g->turn_curr]->done = 1;
		return ;
	}
	take_turn(g);
	g->turn[g->turn_curr + 1]->done = 0;
	g->turn[g->turn_curr]->move = del_movelist(g->turn[g->turn_curr]->move);
	if (!g->turn[g->turn_curr]->move)
		g->turn[g->turn_curr]->done = 1;
	g->turn_curr++;
}

void		start_solve(t_data *d)
{
	if (d->verbosity)
	{
		printf("Solving for a board size %ix%i\n", d->boardsize, d->boardsize);
		// iplement ft_printf_fd
	}
	if (d->verbosity >= 42) // I shouldn't do anything above 3
		ft_putendl("This output is gonna be hella verbose!");
	printf("solving here...\n");
	d->game = new_game(d->boardsize);
	while (d->game->turn[0]->done == 0)
		solve(d, d->game);
}
