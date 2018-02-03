/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othello.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 12:52:12 by irhett            #+#    #+#             */
/*   Updated: 2018/02/02 17:50:38 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHELLO_H
# define OTHELLO_H

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#include <stdio.h> // TODO

#include "libft.h"
#include "othello_structs.h"

#define FREE_SET(foo, bar) if (foo) free(foo); foo = bar

#define DIR_FLAGS_USER (S_IRUSR | S_IWUSR | S_IXUSR)
#define DIR_FLAGS_ELSE (S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)
#define DIRFLAGS (DIR_FLAGS_USER | DIR_FLAGS_ELSE)

#define SIZE g_boardsize

unsigned char	g_boardsize;
// man 2 stat
// man 2 mkdir

/*
 * struct stat st = {0};
 *
 * if (stat("/some/dir", &st) == -1) {
 * 		mkdir("/some/dir", 0744);
 * }
 */

// errors.c
int				parse_error(char *first, char *second);
void			*game_error(void *cleanup, char *message);

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
t_turn			*new_turn(t_player *p);
void			del_turn(t_turn *t);

// t_game.c
t_game			*new_game(void);
t_turn			**make_turns(unsigned int maximum);
t_turn			**extend_game(t_game *g);
void			del_game(t_game *g);

// t_movelist.c
t_movelist		*new_movelist(t_move *data);
t_movelist		*del_movelist(t_movelist *m);
t_movelist		*movelist_add(t_movelist *list, t_move *data);
t_move			*movelist_pop(t_movelist **head);

// t_data.c
t_data			*new_data(void /* args */);
void			del_data(t_data *d);

// solve.c
void			solve(t_data *d, t_game *g);
void			start_solve(t_data *d);

// get_moves.c
t_movelist		*get_all_moves(t_turn *t);
t_movelist		*simplify_moves(t_turn *t, t_movelist *old);

// is_valid_move.c
unsigned int	check_direction(t_turn *t, char r, char c, unsigned char row,
								unsigned char col);
unsigned int	is_valid_move(t_turn *t, unsigned char row, unsigned char col);
void			flip_direction(t_turn *t, t_move *m, char r, char c);
void			place_tile(t_turn *t, t_move *m);

// take_turn.c
void			copy_board(t_turn *src, t_turn *dst);
void			take_turn(t_turn *old, t_turn *nxt);

// stats.c
void			update_stats(t_game *g, t_data *d);
void			handle_stats(t_game *g, t_data *d);
void			final_stats(t_data *d);

// record.c
int				get_move_id(int move_num, int player_value, char *path);
void			make_path(t_game *g);
void			save_file(t_game *g);

// is_game_over.c
int				is_game_over(t_game *g);

// board_dupes.c
unsigned char	get_duplicates(t_turn *turn);

// init_board.c
void			init_board(t_turn *t, t_game *g);

// print_board.c
void			print_board(unsigned char **board);

#endif
