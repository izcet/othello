/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othello.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 12:52:12 by irhett            #+#    #+#             */
/*   Updated: 2017/12/27 15:58:48 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHELLO_H
# define OTHELLO_H

#include <sys/stat.h>
#include <sys/types.h>

#include "libft.h"
#include "othello_structs.h"

// man 2 stat
// man 2 mkdir

/*
 * struct stat st = {0};
 *
 * if (stat("/some/dir", &st) == -1) {
 * 	mkdir("/some/dir", 0700);
 * }
 */

char	*get_move_id(int move_num, int player_id);

void	copy_board_state(t_board *src, t_board *dst);
void	make_move(t_board *b, t_move *m);


#endif
