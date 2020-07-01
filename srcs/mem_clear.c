/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 13:07:51 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/01 18:08:41 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void split_clear(t_split *split)
{
  ft_strdel(&split->str);
  ft_tabdel((void **)split->array, split->len);
}

void map_clear(t_map *map)
{
  ft_tabdel((void **)map->data, map->height);
  ft_tabdel((void **)map->heatmap, map->height);
}

void piece_clear(t_piece *piece)
{
  ft_tabdel((void **)piece->data, piece->height);
}

void player_clear(t_player *player)
{
  ft_memdel((void **)&player->pawns);
}

void filler_clear(t_filler *filler)
{
  map_clear(filler->map);
  ft_memdel((void **)&filler->map);
  piece_clear(filler->piece);
  if (filler->piece)
    ft_memdel((void **)&filler->piece);
  player_clear(filler->me);
  if (filler->me)
    ft_memdel((void **)&filler->me);
  player_clear(filler->opponent);
  if (filler->opponent)
    ft_memdel((void **)&filler->opponent);
}
