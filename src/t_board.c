/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_board.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:40 by irhett            #+#    #+#             */
/*   Updated: 2017/12/27 16:09:40 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		del_board(t_board *b)
{
	if (b)
	{
		/* delete data */
		free(b);
	}
}

t_board	*new_board(void /* args */)
{
	t_board	*b;

	b = (t_board *)malloc(sizeof(t_board));
	if (!b)
		return (NULL);
	/* args */
	return (b);
}
