/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_turn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:42 by irhett            #+#    #+#             */
/*   Updated: 2017/12/27 16:09:42 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		del_turn(t_turn *t)
{
	if (t)
	{
		/* delete data */
		free(t);
	}
}

t_turn	*new_turn(void /* args */)
{
	t_turn	*t;

	t = (t_turn *)malloc(sizeof(t_turn));
	if (!t)
		return (NULL);
	/* args */
	return (t);
}
