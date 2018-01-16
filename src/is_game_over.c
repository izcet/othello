/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:26:55 by irhett            #+#    #+#             */
/*   Updated: 2018/01/15 16:53:01 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

int		is_game_over(t_game *g)
{
	if (g->turn[g->turn_curr]->move)
		return (0);
	// check last board for available moves
	// TODO
	(void)g;
	return (0);
}
