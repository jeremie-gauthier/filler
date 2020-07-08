/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 11:25:39 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/08 11:26:23 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct	s_coord
{
	int		x;
	int		y;
	size_t	dist;
}				t_coord;

typedef struct	s_map
{
	int				width;
	int				height;
	char			**data;
	unsigned int	**heatmap;
}				t_map;

typedef struct	s_pawn
{
	t_coord	coord;
	t_coord	best_spot;
	t_coord	tried_spot;
	t_bool	tested;
	size_t	score;
	t_bool	placeable;
}				t_pawn;

typedef struct	s_player
{
	t_pawn	*pawns;
	size_t	len_pawns;
	char	shape;
}				t_player;

typedef struct	s_piece
{
	int		width;
	int		height;
	char	**data;
	int		offset_width;
	int		offset_height;
	int		true_width;
	int		true_height;
}				t_piece;

typedef struct	s_filler
{
	t_map		*map;
	t_piece		*piece;
	t_player	*me;
	t_player	*opponent;
}				t_filler;

typedef struct	s_split
{
	char	*str;
	char	**array;
	size_t	len;
}				t_split;

typedef struct	s_queue
{
	t_coord	*data;
	size_t	front;
	size_t	rear;
}				t_queue;

#endif
