/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:20:03 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/29 10:47:44 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// DEBUG
void print_pawns(t_player *me)
{
  size_t i;

  i = 0;
  while (i < me->len_pawns)
  {
    ft_dprintf(2, "{red}PAWN >> %i %i %lu{reset}\n",
               me->pawns[i].coord.y,
               me->pawns[i].coord.x,
               me->pawns[i].coord.dist);
    i++;
  }
}

static void pawns_iter_coords(t_filler *filler)
{
  size_t i;

  i = 0;
  while (i < filler->me->len_pawns)
  {
    test_piece_moving_around(&filler->me->pawns[i], filler);
    i++;
  }
}

static t_pawn *pawns_select_best(t_pawn *pawns, size_t len)
{
  size_t i;
  t_pawn *best;

  best = pawns;
  i = 1;
  while (i < len)
  {
    if (pawns[i].placeable && pawns[i].score < best->score)
      best = &pawns[i];
    i++;
  }
  if (best->placeable && best->score != UL_MAX)
    return (best);
  return (NULL);
}

int play_piece(t_filler *filler)
{
  t_pawn *best_pawn;

  if (pawns_init(&filler->me->pawns, filler->map->height * filler->map->width) < 0)
    return (-1);
  // ft_dprintf(2, "Pawns have been sorted !\n");
  pawns_counting(filler);
  pawns_sorting(filler->me->pawns, filler->me->len_pawns);
  print_pawns(filler->me);
  pawns_iter_coords(filler);
  if (!(best_pawn = pawns_select_best(filler->me->pawns, filler->me->len_pawns)))
  {
    ft_dprintf(2, "END WITHOUT SOLUTION\n");
    ft_printf("0 0\n");
  }
  else
  {
    ft_dprintf(2, "{yellow}%i %i{reset}\n",
               best_pawn->best_spot.x - filler->piece->offset_width,
               best_pawn->best_spot.y - filler->piece->offset_height);
    ft_printf("%i %i\n",
              best_pawn->best_spot.y - filler->piece->offset_height,
              best_pawn->best_spot.x - filler->piece->offset_width);
  }
  player_clear(filler->me);
  return (0);
}
