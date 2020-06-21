/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 20:18:16 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/21 11:01:02 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "libft.h"

#define WHITESPACES " \t\n\r\v\f"
#define PLAYER_CASE 0xFFFFFFFF
#define EMPTY_CASE '.'
#define COLD_CASE 0x0
#define INITIAL_DISTANCE 0

typedef struct s_coord
{
  int x;
  int y;
  size_t dist;
} t_coord;

typedef struct s_map
{
  int width;
  int height;
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
  int width;
  int height;
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
int heatmap(t_filler *filler);

/*
**  mem_clear
*/

void filler_clear(t_filler *filler);
void split_clear(t_split *split);
void map_clear(t_map *map);
void piece_clear(t_piece *piece);
void player_clear(t_player *player);
void queue_clear(t_queue *queue);

/*
**  mem_init
*/

int filler_init(t_filler *filler);
int data_init(char ***data, size_t size);
int queue_init(t_queue *queue, size_t size);
int heatmap_init(unsigned int ***heatmap, size_t height, size_t width);

#endif
