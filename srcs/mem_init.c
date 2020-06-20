/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 13:10:21 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/20 12:04:51 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int data_init(char ***data, size_t size)
{
  if (!(*data = (char **)ft_memalloc((size + 1) * sizeof(char *))))
    return (-1);
  return (0);
}

int filler_init(t_filler *filler)
{
  if (!(filler->map = (t_map *)ft_memalloc(sizeof(t_map))))
    return (-1);
  if (!(filler->piece = (t_piece *)ft_memalloc(sizeof(t_piece))))
  {
    ft_memdel((void **)&filler->map);
    return (-1);
  }
  if (!(filler->me = (t_player *)ft_memalloc(sizeof(t_player))))
  {
    ft_memdel((void **)&filler->piece);
    ft_memdel((void **)&filler->map);
    return (-1);
  }
  if (!(filler->opponent = (t_player *)ft_memalloc(sizeof(t_player))))
  {
    ft_memdel((void **)&filler->piece);
    ft_memdel((void **)&filler->map);
    ft_memdel((void **)&filler->me);
    return (-1);
  }
  return (0);
}
