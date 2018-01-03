/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 17:05:36 by irhett            #+#    #+#             */
/*   Updated: 2018/01/03 12:49:53 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		solve(t_data *d, t_game *g)
{
	t_movelist	*list;

	list = NULL;
	if (g->turn_number > g->num_turns)
		extend_game(d->world->game);
	list = get_all_moves(g);
	if (list)
		list = simplify_moves(list, g);
	if (is_game_over(g))
		update_stats(d, g);
	else
	{
		g->turn_number++;
		// iterate through ieach move
		// solve for each sub-set
		// return up one level

	}
	g->turn_number--;
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
	solve(d, d->game);
}
