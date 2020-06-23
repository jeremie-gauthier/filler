/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:20:03 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/23 17:54:35 by jergauth         ###   ########.fr       */
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

static unsigned int select_piece_coords(t_filler *filler)
{
  size_t i;
  int placeable;

  i = 0;
  placeable = 0;
  while (i < filler->me->len_pawns)
  {
    placeable = test_piece_moving_around(&filler->me->pawns[i], filler);
    if (placeable)
      return (i);
    i++;
  }
  return (ERROR_PAWN);
}

int play_piece(t_filler *filler)
{
  unsigned int idx_pawn;

  if (pawns_init(&filler->me->pawns, filler->map->height * filler->map->width) < 0)
    return (-1);
  // ft_dprintf(2, "Pawns have been sorted !\n");
  pawns_counting(filler);
  pawns_sorting(filler->me->pawns, filler->me->len_pawns);
  print_pawns(filler->me);
  idx_pawn = select_piece_coords(filler);
  if (idx_pawn == ERROR_PAWN)
  {
    ft_dprintf(2, "END WITHOUT SOLUTION\n");
    ft_printf("0 0\n");
  }
  else
  {
    ft_dprintf(2, "{yellow}%i %i{reset}\n",
               filler->me->pawns[idx_pawn].best_spot.x - filler->piece->offset_width,
               filler->me->pawns[idx_pawn].best_spot.y - filler->piece->offset_height);
    ft_printf("%i %i\n",
              filler->me->pawns[idx_pawn].best_spot.y - filler->piece->offset_height,
              filler->me->pawns[idx_pawn].best_spot.x - filler->piece->offset_width);
  }
  player_clear(filler->me);
  return (0);
}
