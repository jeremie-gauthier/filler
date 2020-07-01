/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 18:21:42 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/01 17:29:25 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int test_overlapping(t_filler *filler, const t_coord coord,
                            const t_coord dim)
{
  if (is_player_pawn(filler->map->data[coord.y + dim.y][coord.x + dim.x],
                     filler->me->shape) &&
      filler->piece->data[dim.y + filler->piece->offset_height]
                         [dim.x + filler->piece->offset_width] == '*')
  {
    return (1);
  }
  return (0);
}

static int test_score(t_filler *filler, const t_coord coord, const t_coord dim)
{
  if (filler->map->data[coord.y + dim.y][coord.x + dim.x] == '.' &&
      filler->piece->data[dim.y + filler->piece->offset_height]
                         [dim.x + filler->piece->offset_width] == '*')
    return filler->map->heatmap[coord.y + dim.y]
                               [coord.x + dim.x];
  return (0);
}

static int test_piece(const t_coord coord, t_filler *filler, size_t *score)
{
  t_coord dim;
  int overlapping;

  overlapping = 0;
  dim.y = 0;
  while ((dim.y + filler->piece->offset_height) <
         (filler->piece->offset_height + filler->piece->true_height))
  {
    dim.x = 0;
    while ((dim.x + filler->piece->offset_width) <
           (filler->piece->offset_width + filler->piece->true_width))
    {
      if (is_player_pawn(filler->map->data[coord.y + dim.y][coord.x + dim.x],
                         filler->opponent->shape))
        return (0);
      overlapping += test_overlapping(filler, coord, dim);
      *score += test_score(filler, coord, dim);
      dim.x++;
    }
    dim.y++;
  }
  return (overlapping == 1);
}

static void start_test_sequence(t_pawn *target, const t_coord coord,
                                t_filler *filler)
{
  size_t score;

  score = 0;
  target->tried_spot.x = target->coord.x - coord.x + 1;
  target->tried_spot.y = target->coord.y - coord.y + 1;
  if (test_piece(target->tried_spot, filler, &score) == 1 &&
      score < target->score)
  {
    target->score = score;
    target->best_spot = target->tried_spot;
    target->placeable = true;
  }
}

void test_piece_moving_around(t_pawn *target, t_filler *filler)
{
  t_coord coord;

  coord.y = 1;
  while (coord.y <= filler->piece->true_height)
  {
    if ((target->coord.y + filler->piece->true_height - coord.y) <
            filler->map->height &&
        (target->coord.y - coord.y + 1) >= 0)
    {
      coord.x = 1;
      while (coord.x <= filler->piece->true_width)
      {
        if ((target->coord.x + filler->piece->true_width - coord.x) <
                filler->map->width &&
            (target->coord.x - coord.x + 1) >= 0)
          start_test_sequence(target, coord, filler);
        coord.x++;
      }
    }
    coord.y++;
  }
}
