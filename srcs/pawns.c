/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pawns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:51:20 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/23 11:39:06 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int is_player_pawn(const char pawn, const char player_pawn)
{
  return (pawn == player_pawn || pawn == (player_pawn + 32));
}

static unsigned int find_min_dist(t_filler *filler, t_coord coord)
{
  unsigned int min;
  unsigned int **heatmap;

  heatmap = filler->map->heatmap;
  min = PLAYER_CASE;
  if (coord.y - 1 > 0 && heatmap[coord.y - 1][coord.x] < min)
    min = heatmap[coord.y - 1][coord.x];
  if (coord.x + 1 < filler->map->width && heatmap[coord.y][coord.x + 1] < min)
    min = heatmap[coord.y][coord.x + 1];
  if (coord.y + 1 < filler->map->height && heatmap[coord.y + 1][coord.x] < min)
    min = heatmap[coord.y - 1][coord.x];
  if (coord.x - 1 > 0 && heatmap[coord.y][coord.x - 1] < min)
    min = heatmap[coord.y][coord.x - 1];
  return min;
}

static int pawns_add(t_filler *filler, t_coord coord, size_t idx)
{
  t_pawn pawn;

  ft_bzero((void *)&pawn, sizeof(t_pawn));
  pawn.coord = coord;
  pawn.coord.dist = find_min_dist(filler, coord);
  if (pawn.coord.dist < PLAYER_CASE)
  {
    filler->me->pawns[idx] = pawn;
    return (1);
  }
  return (0);
}

void pawns_counting(t_filler *filler)
{
  t_coord coord;
  size_t idx;

  idx = 0;
  coord.y = 0;
  while (coord.y < filler->map->height)
  {
    coord.x = 0;
    while (coord.x < filler->map->width)
    {
      if (is_player_pawn(filler->map->data[coord.y][coord.x],
                         filler->me->shape))
        idx += pawns_add(filler, coord, idx);
      coord.x++;
    }
    coord.y++;
  }
  filler->me->len_pawns = idx;
}

size_t find_pawn_with_min_dist(t_pawn *pawns, size_t len, unsigned int ignore_lt)
{
  size_t i;
  unsigned int min;
  size_t min_idx;

  i = 0;
  min = PLAYER_CASE;
  min_idx = PLAYER_CASE;
  while (i < len)
  {
    if (pawns[i].coord.dist >= ignore_lt && !pawns[i].tested)
    {
      if (pawns[i].coord.dist == ignore_lt)
        return i;
      if (pawns[i].coord.dist < min)
      {
        min = pawns[i].coord.dist;
        min_idx = i;
      }
    }
    i++;
  }
  return min_idx;
}
