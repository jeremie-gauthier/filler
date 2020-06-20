/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:12:59 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/20 19:06:31 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int is_empty_case(t_filler *filler, t_coord coord)
{
  return filler->map->data[coord.y][coord.x] == EMPTY_CASE;
}

static int is_ennemy(const char pawn, const char ennemy_pawn)
{
  return (pawn == ennemy_pawn || pawn == (ennemy_pawn + 32));
}

static void enqueu_if_opponent_case(t_queue *queue, t_filler *filler, t_coord coord)
{
  size_t idx_marked;
  t_coord coord_marked;

  if (is_ennemy(filler->opponent->shape, filler->map->data[coord.y][coord.x]))
  {
    ft_dprintf(2, "!!! DETECT ENNEMY AT %lu %lu\n", coord.y, coord.x);
    // TOP
    coord_marked = coord;
    coord_marked.y--;
    idx_marked = (coord.y - 1) * filler->map->height + coord.x;
    if (coord.y - 1 > 0 && is_empty_case(filler, coord_marked) && !queue->marked[idx_marked])
    {
      queue->data[queue->rear++] = coord_marked;
      queue->marked[idx_marked] = MARKED;
    }
    // RIGHT
    coord_marked = coord;
    coord_marked.x++;
    idx_marked = coord.y * filler->map->height + coord.x + 1;
    if (coord.x + 1 < filler->map->width && is_empty_case(filler, coord_marked) && !queue->marked[idx_marked])
    {
      queue->data[queue->rear++] = coord_marked;
      queue->marked[idx_marked] = MARKED;
    }
    // BOTTOM
    coord_marked = coord;
    coord_marked.y++;
    idx_marked = (coord.y + 1) * filler->map->height + coord.x;
    if (coord.y + 1 < filler->map->height && is_empty_case(filler, coord_marked) && !queue->marked[idx_marked])
    {
      queue->data[queue->rear++] = coord_marked;
      queue->marked[idx_marked] = MARKED;
    }
    // LEFT
    coord_marked = coord;
    coord_marked.x--;
    idx_marked = (coord.y + 1) * filler->map->height + coord.x;
    if (coord.x > 0 && is_empty_case(filler, coord_marked) && !queue->marked[idx_marked])
    {
      queue->data[queue->rear++] = coord_marked;
      queue->marked[idx_marked] = MARKED;
    }
  }
}

static int heatmap_setup(t_filler *filler, t_queue *queue)
{
  t_coord coord;

  coord.y = 0;
  while (coord.y < filler->map->height)
  {
    coord.x = 0;
    while (coord.x < filler->map->width)
    {
      if (filler->map->data[coord.y][coord.x] != EMPTY_CASE)
      {
        filler->map->heatmap[coord.y][coord.x] = PLAYER_CASE;
        enqueu_if_opponent_case(queue, filler, coord);
      }
      coord.x++;
    }
    coord.y++;
  }
  return (0);
}

int heatmap(t_filler *filler)
{
  t_queue queue;

  if (heatmap_init(&filler->map->heatmap, filler->map->height, filler->map->width) < 0)
    return (-1); //Possible leak if loop
  if (queue_init(&queue, filler->map->height * filler->map->width) < 0)
    return (-1);
  if (heatmap_setup(filler, &queue) < 0)
  {
    queue_clear(&queue);
    return (-1);
  }
  ft_dprintf(2, "%lu %lu\n", queue.data[0].y, queue.data[0].x);
  queue_clear(&queue);
  return (0);
}
