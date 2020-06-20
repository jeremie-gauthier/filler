/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 20:18:16 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/20 12:04:46 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "libft.h"

#define WHITESPACES " \t\n\r\v\f"
#define PLAYER_CASE 0xFFFFFFFF
#define FREE_CASE 0x0
#define EMPTY_CASE '.'
#define MARKED 0x1

typedef struct s_coord
{
  size_t x;
  size_t y;
} t_coord;

typedef struct s_map
{
  size_t width;
  size_t height;
  char **data;
  unsigned int **heatmap;
} t_map;

typedef struct s_player
{
  t_coord *last_move;
  size_t len;
  char shape;
} t_player;

typedef struct s_piece
{
  size_t width;
  size_t height;
  char **data;
} t_piece;

typedef struct s_filler
{
  t_map *map;
  t_piece *piece;
  t_player *me;
  t_player *opponent;
} t_filler;

typedef struct s_split
{
  char *str;
  char **array;
  size_t len;
} t_split;

typedef struct s_queue
{
  t_coord *data;
  char *marked;
  size_t front;
  size_t rear;
} t_queue;

/*
**  core
*/

int read_map(char *line, t_filler *filler);
int read_piece(char *line, t_filler *filler);
int play_piece(t_filler *filler);

/*
**  mem_clear
*/

void filler_clear(t_filler *filler);
void split_clear(t_split *split);
void map_clear(t_map *map);
void piece_clear(t_piece *piece);
void player_clear(t_player *player);

/*
**  mem_init
*/

int filler_init(t_filler *filler);
int data_init(char ***data, size_t size);

#endif
