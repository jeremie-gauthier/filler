/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:20:03 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/23 12:14:05 by jergauth         ###   ########.fr       */
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
  size_t nb_visited;
  unsigned int idx_pawn;
  unsigned int ignore_lt;
  int placeable;

  placeable = 0;
  ignore_lt = 0;
  idx_pawn = 0;
  nb_visited = 0;
  while (!placeable && nb_visited < filler->me->len_pawns)
  {
    idx_pawn = find_pawn_with_min_dist(&filler->me->pawns[idx_pawn],
                                       filler->me->len_pawns, ignore_lt);
    ignore_lt = filler->me->pawns[idx_pawn].coord.dist;
    filler->me->pawns[idx_pawn].tested = true;
    nb_visited++;
    if (idx_pawn < filler->me->len_pawns)
    {
      ft_dprintf(2, "{green}PAWN >> %i %i %lu{reset}\n",
                 filler->me->pawns[idx_pawn].coord.y,
                 filler->me->pawns[idx_pawn].coord.x,
                 filler->me->pawns[idx_pawn].coord.dist);
      placeable = test_piece_moving_around(&filler->me->pawns[idx_pawn], filler);
    }
    else
    {
      idx_pawn = 0;
      ignore_lt++;
    }
  }
  ft_dprintf(2, "PLACEABLE => %i\n", placeable);
  return (placeable ? idx_pawn : ERROR_PAWN);
}

int play_piece(t_filler *filler)
{
  unsigned int idx_pawn;

  if (pawns_init(&filler->me->pawns, filler->map->height * filler->map->width) < 0)
    return (-1);
  pawns_counting(filler);
  print_pawns(filler->me);
  if ((idx_pawn = select_piece_coords(filler)) == ERROR_PAWN)
  {
    player_clear(filler->me);
    return (-1);
  }
  ft_printf("%i %i\n",
            filler->me->pawns[idx_pawn].best_spot.x - filler->piece->offset_width,
            filler->me->pawns[idx_pawn].best_spot.y - filler->piece->offset_height);
  player_clear(filler->me);
  return (0);
}
