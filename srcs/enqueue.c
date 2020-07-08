/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 11:59:41 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/08 11:31:18 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	enqueu_top_of(t_coord coord, t_queue *queue, t_filler *filler)
{
	coord.y--;
	if (coord.y >= 0 &&
		is_empty_case(filler, coord) &&
		!is_in_queue(coord, queue))
	{
		queue->data[queue->rear++] = coord;
		filler->map->heatmap[coord.y][coord.x] = coord.dist;
	}
}

static void	enqueu_right_of(t_coord coord, t_queue *queue, t_filler *filler)
{
	coord.x++;
	if (coord.x < filler->map->width &&
		is_empty_case(filler, coord) &&
		!is_in_queue(coord, queue))
	{
		queue->data[queue->rear++] = coord;
		filler->map->heatmap[coord.y][coord.x] = coord.dist;
	}
}

static void	enqueu_bottom_of(t_coord coord, t_queue *queue, t_filler *filler)
{
	coord.y++;
	if (coord.y < filler->map->height &&
		is_empty_case(filler, coord) &&
		!is_in_queue(coord, queue))
	{
		queue->data[queue->rear++] = coord;
		filler->map->heatmap[coord.y][coord.x] = coord.dist;
	}
}

static void	enqueu_left_of(t_coord coord, t_queue *queue, t_filler *filler)
{
	coord.x--;
	if (coord.x >= 0 &&
		is_empty_case(filler, coord) &&
		!is_in_queue(coord, queue))
	{
		queue->data[queue->rear++] = coord;
		filler->map->heatmap[coord.y][coord.x] = coord.dist;
	}
}

void		enqueue_procedure(t_coord coord, t_queue *queue, t_filler *filler)
{
	coord.dist++;
	enqueu_top_of(coord, queue, filler);
	enqueu_right_of(coord, queue, filler);
	enqueu_bottom_of(coord, queue, filler);
	enqueu_left_of(coord, queue, filler);
}
