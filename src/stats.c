/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:14:12 by irhett            #+#    #+#             */
/*   Updated: 2018/01/31 18:16:55 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"


void		update_stats(t_game *g, t_data *d)
{
	(void)g;
	(void)d;
}

void		handle_stats(t_game *g, t_data *d)
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
