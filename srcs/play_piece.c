/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:20:03 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/22 13:44:50 by jergauth         ###   ########.fr       */
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

int play_piece(t_filler *filler)
{
  unsigned int idx_pawn;

  if (pawns_init(&filler->me->pawns, filler->map->height * filler->map->width) < 0)
    return (-1);
  pawns_counting(filler);
  print_pawns(filler->me);
  idx_pawn = find_pawn_with_min_dist(filler->me->pawns, filler->me->len_pawns, 0);
  ft_dprintf(2, "{green}PAWN >> %i %i %lu{reset}\n",
             filler->me->pawns[idx_pawn].coord.y,
             filler->me->pawns[idx_pawn].coord.x,
             filler->me->pawns[idx_pawn].coord.dist);
  player_clear(filler->me);
  return (0);
}
