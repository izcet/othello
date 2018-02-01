/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:14:12 by irhett            #+#    #+#             */
/*   Updated: 2018/01/31 17:45:05 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"


void		make_path(t_game *g)
{
	int		turn;
	char	path[g->turn_size * 4];

	bzero(path, g->turn_size * 4);
	turn = 0;
	while (turn < g->turn_last)
	{
		turn++;
	}
}

void		save_file(t_game *g)
{
	(void)g;
}

void		update_stats(t_game *g, t_data *d)
{
	(void)g;
	(void)d;
}

void		record_stats(t_game *g, t_data *d)
{
	make_path(g);
	save_file(g);
	update_stats(g, d);
}

void		final_stats(t_data *d)
{
	// TODO
	(void)d;

}
