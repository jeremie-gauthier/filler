/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 20:18:16 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/29 09:18:55 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "libft.h"

#define WHITESPACES " \t\n\r\v\f"
#define ERROR_PAWN 0xFFFFFFFF
#define PLAYER_CASE 0xFFFFFFFF
#define NO_PLAYER_CASE 0xFFFFFFFE
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

typedef struct s_pawn
{
  // Si je veux tirer profit du `score`,
  // il faut ajouter une autre struct coord
  // correspondant au placement de la piece par rapport
  // au pion situe en `coord`
  // Ce sera une position abosule de la filler->map->data
  t_coord coord;
  t_coord best_spot;
  t_bool tested;
  size_t score;
} t_pawn;

typedef struct s_player
{
  t_pawn *pawns;
  size_t len_pawns;
  t_coord *last_move; //useless ?
  size_t len;         //useless ?
  char shape;
} t_player;

typedef struct s_piece
{
  int width;
  int height;
  char **data;
  int offset_width;
  int offset_height;
  int true_width;
  int true_height;
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
  size_t front;
  size_t rear;
} t_queue;

/*
**  core
*/

int read_map(char *line, t_filler *filler);
int read_piece(char *line, t_filler *filler);

// Should go static
int test_piece(t_coord coord, t_filler *filler);
int test_piece_moving_around(t_pawn *target, t_filler *filler);

int play_piece(t_filler *filler);
int heatmap(t_filler *filler);
int is_empty_row(const char *row);
int is_empty_col(char **array, size_t idx_col);

/*
**  queue
*/
void enqueue_procedure(t_coord coord, t_queue *queue, t_filler *filler);

/*
**  pawns
*/
void pawns_counting(t_filler *filler);
int is_player_pawn(const char pawn, const char player_pawn);
void pawns_sorting(t_pawn *pawns, size_t len);

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
int pawns_init(t_pawn **pawns, size_t size);
int data_init(char ***data, size_t size);
int queue_init(t_queue *queue, size_t size);
int heatmap_init(unsigned int ***heatmap, int height, int width);

#endif
