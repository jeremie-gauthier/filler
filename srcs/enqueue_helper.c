/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:32:18 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/08 11:32:17 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	is_in_queue(const t_coord coord, t_queue *queue)
{
	size_t i;

	i = queue->front;
	while (i < queue->rear)
	{
		if (queue->data[i].x == coord.x && queue->data[i].y == coord.y)
			return (1);
		i++;
	}
	return (0);
}

int	is_empty_case(t_filler *filler, const t_coord coord)
{
	return (filler->map->data[coord.y][coord.x] == EMPTY_CASE &&
			filler->map->heatmap[coord.y][coord.x] == COLD_CASE);
}
