/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 13:10:21 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/16 15:26:32 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int map_init(t_filler *filler)
{
  if (!(filler->map->data = (char **)malloc((filler->map->height + 1) * sizeof(char))))
    return (-1);
  return (0);
}

int filler_init(t_filler *filler)
{
  if (!(filler->map = (t_map *)malloc(sizeof(t_map))))
    return (-1);
  ft_bzero(filler->map, sizeof(t_map));
  if (!(filler->me = (t_player *)malloc(sizeof(t_player))))
  {
    ft_memdel((void **)&filler->map);
    return (-1);
  }
  ft_bzero(filler->me, sizeof(t_player));
  if (!(filler->opponent = (t_player *)malloc(sizeof(t_player))))
  {
    ft_memdel((void **)&filler->map);
    ft_memdel((void **)&filler->me);
    return (-1);
  }
  ft_bzero(filler->opponent, sizeof(t_player));
  return (0);
}
