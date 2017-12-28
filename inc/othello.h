/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othello.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 12:52:12 by irhett            #+#    #+#             */
/*   Updated: 2017/12/27 19:33:38 by irhett           ###   ########.fr       */
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

void		*game_error(void *cleanup, char *message);

char		*get_move_id(int move_num, int player_id);

void		copy_board_state(t_board *src, t_board *dst);
void		make_move(t_board *b, t_move *m);

t_player	*new_player(void /* args */);
void		del_player(t_player *p);

t_board		*new_board(unsigned char size);
void		del_board(t_board *b);

t_move		*new_move(void /* args */);
void		del_move(t_move *m);

t_turn		*new_turn(void /* args */);
void		del_turn(t_turn *t);

t_game		*new_game(unsigned char size);
void		del_game(t_game *g);

t_world		*new_world(void /* args */);
void		del_world(t_world *w);

#endif
