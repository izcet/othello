/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othello.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 12:52:12 by irhett            #+#    #+#             */
/*   Updated: 2017/12/28 20:48:59 by irhett           ###   ########.fr       */
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

// game_error.c
void		*game_error(void *cleanup, char *message);

// get_move_id.c
char		*get_move_id(int move_num, int player_id);


void		copy_board_state(t_turn *src, t_turn *dst);
void		make_move(t_turn *b, t_move *m); // TODO <<

// t_player.c
t_player	*new_player(char symbol, char value);
void		del_player(t_player *p);
t_player	*make_black_player(void);
t_player	*make_white_player(void);
int			make_players(t_game *g);

// t_move.c
t_move		*new_move(void /* args */);
void		del_move(t_move *m);

// t_turn.c
t_turn		*new_turn(void /* args */);
void		del_turn(t_turn *t);

// t_game.c
t_game		*new_game(unsigned char size);
t_turn		**make_turns(unsigned int maximum);
t_turn		**extend_game(t_game *g);
void		del_game(t_game *g);

// t_world.c
t_world		*new_world(void /* args */);
void		del_world(t_world *w);

// t_movelist.c
t_movelist	*new_movelist(void /* args */);
void		del_movelist(t_movelist *m);

#endif
