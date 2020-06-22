/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 18:21:42 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/22 20:47:23 by jergauth         ###   ########.fr       */
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

int test_piece(t_coord coord, t_filler *filler)
{
  int h;
  int w;
  int overlapping;

  ft_dprintf(2, "TEST: [%i, %i]\n", coord.y, coord.x);
  overlapping = 0;
  h = 0;
  while ((h + filler->piece->offset_height) < filler->piece->height &&
         (coord.y + h) < filler->map->height &&
         !is_empty_row(filler->piece->data[h]))
  {
    w = 0;
    while ((w + filler->piece->offset_width) < filler->piece->width &&
           (coord.x + w) < filler->map->width &&
           !is_empty_col(filler->piece->data, w))
    {
      ft_dprintf(2, "CHECKING: [%i, %i]\n", coord.y + h, coord.x + w);
      if (filler->map->data[coord.y + h]
                           [coord.x + w] == '*' &&
          filler->piece->data[h + filler->piece->offset_height]
                             [w + filler->piece->offset_width] == '*')
        overlapping++;
      w++;
    }
    h++;
  }
  return (overlapping == 1);
}

int test_piece_moving_around(t_pawn target, t_filler *filler)
{
  t_coord coord;
  t_coord to_test;

  coord.y = 1;
  while (coord.y <= filler->piece->true_height)
  {
    if ((target.coord.y + filler->piece->true_height - coord.y) < filler->map->height &&
        (target.coord.y - coord.y + 1) >= 0)
    {
      ft_dprintf(2, "PASS 1st condition\n");
      coord.x = 1;
      while (coord.x <= filler->piece->true_width)
      {
        if ((target.coord.x + filler->piece->true_width - coord.x) < filler->map->width &&
            (target.coord.x - coord.x + 1) >= 0)
        {
          ft_dprintf(2, "PASS 2nd condition\n");
          to_test.x = target.coord.x - coord.x + 1;
          to_test.y = target.coord.y - coord.y + 2;
          if (test_piece(to_test, filler) == 1)
          {
            ft_dprintf(2, "{green}FOUND A PLACE @ [%i, %i]{reset}\n", to_test.y, to_test.x);
            return (1);
          }
        }
        coord.x++;
      }
    }
    coord.y++;
  }
  return (0);
}
