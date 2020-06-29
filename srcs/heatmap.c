/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:12:59 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/29 09:07:00 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// DEBUG
void print_heatmap(t_filler *filler)
{
  int h, w;

  h = 0;
  while (h < filler->map->height)
  {
    w = 0;
    while (w < filler->map->width)
    {
      if (filler->map->heatmap[h][w] == PLAYER_CASE)
        ft_dprintf(2, "{green}%2u{reset} ", 0);
      else if (filler->map->heatmap[h][w] == NO_PLAYER_CASE)
        ft_dprintf(2, "{yellow} .{reset} ");
      else
        ft_dprintf(2, "%2u ", filler->map->heatmap[h][w]);
      w++;
    }
    ft_dprintf(2, "\n");
    h++;
  }
  ft_dprintf(2, "\n\n");
}

static void enqueu_if_opponent_case(t_queue *queue, t_filler *filler,
                                    t_coord coord)
{
  if (is_player_pawn(filler->map->data[coord.y][coord.x],
                     filler->opponent->shape))
    enqueue_procedure(coord, queue, filler);
}

static int heatmap_setup(t_filler *filler, t_queue *queue)
{
  t_coord coord;

  coord.dist = INITIAL_DISTANCE;
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

void heatmap_spread(t_filler *filler, t_queue *queue)
{
  while (queue->front < queue->rear)
  {
    enqueue_procedure(queue->data[queue->front], queue, filler);
    queue->front++;
  }
}

static void heatmap_unreachable_cases(t_filler *filler)
{
  int h;
  int w;

  h = 0;
  while (h < filler->map->height)
  {
    w = 0;
    while (w < filler->map->width)
    {
      if (filler->map->heatmap[h][w] == 0)
        filler->map->heatmap[h][w] = NO_PLAYER_CASE;
      w++;
    }
    h++;
  }
}

int heatmap(t_filler *filler)
{
  t_queue queue;

  if (heatmap_init(&filler->map->heatmap, filler->map->height, filler->map->width) < 0)
    return (-1);
  if (queue_init(&queue, filler->map->height * filler->map->width) < 0)
    return (-1);
  if (heatmap_setup(filler, &queue) < 0)
  {
    queue_clear(&queue);
    return (-1);
  }
  heatmap_spread(filler, &queue);
  heatmap_unreachable_cases(filler);
  print_heatmap(filler);
  queue_clear(&queue);
  return (0);
}
