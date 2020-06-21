/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:12:59 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/21 11:02:01 by jergauth         ###   ########.fr       */
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
      if (filler->map->heatmap[h][w] == 4294967295)
        ft_dprintf(2, "{green}%2lu{reset} ", 0);
      else
        ft_dprintf(2, "%2lu ", filler->map->heatmap[h][w]);
      w++;
    }
    ft_dprintf(2, "\n");
    h++;
  }
  ft_dprintf(2, "\n\n");
}

int is_in_queue(t_coord coord, t_queue *queue)
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

static int is_empty_case(t_filler *filler, t_coord coord)
{
  return filler->map->data[coord.y][coord.x] == EMPTY_CASE && filler->map->heatmap[coord.y][coord.x] == COLD_CASE;
}

void enqueu_top_of(t_coord coord, t_queue *queue, t_filler *filler)
{
  coord.y--;
  if (coord.y >= 0 && is_empty_case(filler, coord) && !is_in_queue(coord, queue))
  {
    queue->data[queue->rear++] = coord;
    filler->map->heatmap[coord.y][coord.x] = coord.dist;
  }
}

void enqueu_right_of(t_coord coord, t_queue *queue, t_filler *filler)
{
  coord.x++;
  if (coord.x < filler->map->width && is_empty_case(filler, coord) && !is_in_queue(coord, queue))
  {
    queue->data[queue->rear++] = coord;
    filler->map->heatmap[coord.y][coord.x] = coord.dist;
  }
}

void enqueu_bottom_of(t_coord coord, t_queue *queue, t_filler *filler)
{
  coord.y++;
  if (coord.y < filler->map->height && is_empty_case(filler, coord) && !is_in_queue(coord, queue))
  {
    queue->data[queue->rear++] = coord;
    filler->map->heatmap[coord.y][coord.x] = coord.dist;
  }
}

void enqueu_left_of(t_coord coord, t_queue *queue, t_filler *filler)
{
  coord.x--;
  if (coord.x >= 0 && is_empty_case(filler, coord) && !is_in_queue(coord, queue))
  {
    queue->data[queue->rear++] = coord;
    filler->map->heatmap[coord.y][coord.x] = coord.dist;
  }
}

void enqueue_procedure(t_coord coord, t_queue *queue, t_filler *filler)
{
  coord.dist++;
  enqueu_top_of(coord, queue, filler);
  enqueu_right_of(coord, queue, filler);
  enqueu_bottom_of(coord, queue, filler);
  enqueu_left_of(coord, queue, filler);
}

static void enqueu_if_opponent_case(t_queue *queue, t_filler *filler, t_coord coord)
{
  char pawn;
  char ennemy_pawn;

  pawn = filler->map->data[coord.y][coord.x];
  ennemy_pawn = filler->opponent->shape;
  if (pawn == ennemy_pawn || pawn == (ennemy_pawn + 32))
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
    // print_heatmap(filler);
    queue->front++;
    // ft_dprintf(2, "{cyan}%lu/%lu{reset}\n", queue->front, queue->rear);
  }
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
  heatmap_spread(filler, &queue);
  print_heatmap(filler);
  queue_clear(&queue);
  return (0);
}
