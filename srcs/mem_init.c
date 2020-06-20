/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 13:10:21 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/20 18:53:25 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int data_init(char ***data, size_t size)
{
  if (!(*data = (char **)ft_memalloc((size + 1) * sizeof(char *))))
    return (-1);
  return (0);
}

int heatmap_init(unsigned int ***heatmap, size_t height, size_t width)
{
  size_t h;

  h = 0;
  if (!(*heatmap = (unsigned int **)ft_memalloc(height * sizeof(unsigned int *))))
    return (-1);
  while (h < height)
  {
    if (!((*heatmap)[h] = (unsigned int *)ft_memalloc(width * sizeof(unsigned int))))
    {
      ft_tabdel((void **)*heatmap, h);
      return (-1);
    }
    h++;
  }
  return (0);
}

int queue_init(t_queue *queue, size_t size)
{
  if (!(queue->data = (t_coord *)ft_memalloc(size * sizeof(t_coord))))
    return (-1);
  if (!(queue->marked = (char *)ft_memalloc(size * sizeof(char))))
  {
    ft_memdel((void **)&queue->data);
    return (-1);
  }
  queue->front = 0;
  queue->rear = 0;
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
