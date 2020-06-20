/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 20:18:16 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/16 15:25:58 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "libft.h"

#define WHITESPACES " \t\n\r\v\f"

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
  char **heatmap;
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

int read_map(char *line, t_filler *filler);
int read_piece(char *line, t_filler *filler);
int play_piece(t_filler *filler);

/*
**  mem_clear
*/

void filler_clear(t_filler *filler);
void split_clear(t_split *split);

/*
**  mem_init
*/

int map_init(t_filler *filler);
int filler_init(t_filler *filler);

#endif
