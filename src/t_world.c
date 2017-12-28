/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_world.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:44 by irhett            #+#    #+#             */
/*   Updated: 2017/12/27 16:09:44 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

void		del_world(t_world *w)
{
	if (w)
	{
		/* delete data */
		free(w);
	}
}

t_world	*new_world(void /* args */)
{
	t_world	*w;

	w = (t_world *)malloc(sizeof(t_world));
	if (!w)
		return (NULL);
	/* args */
	return (w);
}
