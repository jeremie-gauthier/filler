/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 18:21:42 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/29 11:08:57 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int is_empty_row(const char *row)
{
  return ft_strchr(row, '*') == NULL;
}

int is_empty_col(char **array, size_t idx_col)
{
  size_t row;

  row = 0;
  while (array[row])
  {
    if (array[row][idx_col] == '*')
      return (0);
    row++;
  }
  return (1);
}

int test_piece(t_coord coord, t_filler *filler, size_t *score)
{
  int h;
  int w;
  int overlapping;

  overlapping = 0;
  h = 0;
  while ((h + filler->piece->offset_height) < (filler->piece->offset_height + filler->piece->true_height))
  {
    w = 0;
    while ((w + filler->piece->offset_width) < (filler->piece->offset_width + filler->piece->true_width))
    {
      if (is_player_pawn(filler->map->data[coord.y + h][coord.x + w],
                         filler->opponent->shape))
        return (0);
      if (is_player_pawn(filler->map->data[coord.y + h][coord.x + w],
                         filler->me->shape) &&
          filler->piece->data[h + filler->piece->offset_height]
                             [w + filler->piece->offset_width] == '*')
        overlapping++;
      else if (filler->map->data[coord.y + h][coord.x + w] == '.' && filler->piece->data[h + filler->piece->offset_height]
                                                                                        [w + filler->piece->offset_width] == '*')
        (*score) += filler->map->heatmap[coord.y + h]
                                        [coord.x + w];
      w++;
    }
    h++;
  }
  return (overlapping == 1);
}

void test_piece_moving_around(t_pawn *target, t_filler *filler)
{
  t_coord coord;
  size_t score;

  coord.y = 1;
  while (coord.y <= filler->piece->true_height)
  {
    if ((target->coord.y + filler->piece->true_height - coord.y) < filler->map->height &&
        (target->coord.y - coord.y + 1) >= 0)
    {
      coord.x = 1;
      while (coord.x <= filler->piece->true_width)
      {
        if ((target->coord.x + filler->piece->true_width - coord.x) < filler->map->width &&
            (target->coord.x - coord.x + 1) >= 0)
        {
          score = 0;
          target->tried_spot.x = target->coord.x - coord.x + 1;
          target->tried_spot.y = target->coord.y - coord.y + 1;
          if (test_piece(target->tried_spot, filler, &score) == 1 && score < target->score)
          {
            target->score = score;
            target->best_spot = target->tried_spot;
            target->placeable = true;
          }
        }
        coord.x++;
      }
    }
    coord.y++;
  }
}
