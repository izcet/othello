/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othello.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 12:52:12 by irhett            #+#    #+#             */
/*   Updated: 2017/12/29 19:45:58 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHELLO_H
# define OTHELLO_H

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include <stdio.h> // TODO

#include "libft.h"
#include "othello_structs.h"

#define FREE_SET(foo, bar) if (foo) free(foo); foo = bar

// man 2 stat
// man 2 mkdir

/*
 * struct stat st = {0};
 *
 * if (stat("/some/dir", &st) == -1) {
 * 		mkdir("/some/dir", 0744);
 * }
 */

// game_error.c
void			*game_error(void *cleanup, char *message);

// get_move_id.c
char			*get_move_id(int move_num, int player_id);

// t_player.c
t_player		*new_player(char symbol, char value);
void			del_player(t_player *p);
t_player		*make_black_player(void);
t_player		*make_white_player(void);
int				make_players(t_game *g);

// t_move.c
t_move			*new_move(unsigned char x, unsigned char y, unsigned int id, 
							unsigned int flipped, t_player *active);
void			del_move(t_move *m);

// t_turn.c
t_turn			*new_turn(unsigned char size, unsigned int id, t_player *p);
void			del_turn(t_turn *t);

// t_game.c
t_game			*new_game(unsigned char size);
t_turn			**make_turns(unsigned int maximum);
t_turn			**extend_game(t_game *g);
void			del_game(t_game *g);

// t_world.c
t_world			*new_world(unsigned char size);
void			del_world(t_world *w);

// t_movelist.c
t_movelist		*new_movelist(t_move *data);
void			del_movelist(t_movelist *m);
t_movelist		*movelist_add(t_movelist *list, t_move *data);
t_move			*movelist_pop(t_movelist **head);

// t_data.c
t_data			*new_data(void /* args */);
void			del_data(t_data *d);

// solve.c
void			solve(t_data *d);

void			copy_board_state(t_turn *src, t_turn *dst);
void			make_move(t_turn *b, t_move *m); // TODO <<

#endif
