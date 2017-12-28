/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_board.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:09:40 by irhett            #+#    #+#             */
/*   Updated: 2017/12/27 19:37:35 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "othello.h"

/*
 * - Board contains a pointer to Turn, which also points back to Board
 * - Freeing either will not be part of the individuals' code, but part of the 
 * 		calling program.
 * - There will be a "zipper" function that handles the cross-pointing of the
 *   	arrays of boards (two arrays of the structs are used because it allows
 *   	for less syscalls to malloc)
 */

void		del_board(t_board *b)
{
	unsigned char	i;

	if (b)
	{
		if (b->tiles)
		{
			i = 0;
			while (i < size)
			{
				if (b->tiles[i])
					free(b->tiles[i]);
				i++;
			}
			free(b->tiles);
		}
		free(b);
	}
}

t_board	*new_board(unsigned char size)
{
	t_board			*b;
	unsigned char	i;

	b = (t_board *)malloc(sizeof(t_board));
	if (!b)
		return (game_error(NULL, "new_board malloc() of b"));
	b->tiles = (char **)malloc(sizeof(char *) * size);
	if (!b->tiles)
		return (game_error(b, "new_board malloc() of b->tiles"));
	i = 0;
	while (i < size)
	{
		b->tiles[i] = (char *)malloc(sizeof(char) * size);
		if (!b->tiles[i++])
		{
			del_board(b);
			return (game_error(NULL, "new_board malloc() of b->tiles[i]"));
		}
	}
	b->size = size;
	b->num_black = 0;
	b->num_white = 0;
	b->num_empty = size * size;
	b->turn = NULL;
	return (b);
}
