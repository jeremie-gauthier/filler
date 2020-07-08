/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 20:18:16 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/08 11:26:51 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "types.h"

# define WHITESPACES " \t\n\r\v\f"
# define UL_MAX 0xFFFFFFFFFFFFFFFF
# define PLAYER_CASE 0xFFFFFFFF
# define NO_PLAYER_CASE 0xFFFFFFFE
# define EMPTY_CASE '.'
# define COLD_CASE 0x0
# define INITIAL_DISTANCE 0

/*
**  core
*/

int		is_empty_row(const char *row);
int		is_empty_col(const char **array, const size_t idx_col);
int		read_map(const char *line, t_filler *filler);
int		heatmap(t_filler *filler);
int		read_piece(const char *line, t_filler *filler);
void	test_piece_moving_around(t_pawn *target, t_filler *filler);
int		play_piece(t_filler *filler);

/*
**  queue
*/

int		is_in_queue(const t_coord coord, t_queue *queue);
int		is_empty_case(t_filler *filler, const t_coord coord);
void	enqueue_procedure(t_coord coord, t_queue *queue, t_filler *filler);

/*
**  pawns
*/

void	pawns_counting(t_filler *filler);
int		is_player_pawn(const char pawn, const char player_pawn);
void	pawns_sorting(t_pawn *pawns, const size_t len);

/*
**  mem_clear
*/

void	filler_clear(t_filler *filler);
void	split_clear(t_split *split);
void	map_clear(t_map *map);
void	piece_clear(t_piece *piece);
void	player_clear(t_player *player);
void	queue_clear(t_queue *queue);

/*
**  mem_init
*/

int		filler_init(t_filler *filler);
int		pawns_init(t_pawn **pawns, const size_t size);
int		data_init(char ***data, const int size);
int		queue_init(t_queue *queue, const size_t size);
int		heatmap_init(unsigned int ***heatmap, const int height,
						const int width);

#endif
