/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:17:50 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/16 15:27:41 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int read_map_header(char *line, t_filler *filler)
{
  t_split data;

  ft_bzero(&data, sizeof(t_split));
  if (!(data.array = ft_strsplit(line, WHITESPACES, &data.len)))
    return (-1);
  filler->map->height = ft_atoi(data.array[1]);
  filler->map->width = ft_atoi(data.array[2]);
  ft_tabdel((void **)data.array, data.len);
  return (0);
}

static int read_map_body(t_filler *filler)
{
  t_split data;
  size_t i;

  i = 0;
  ft_bzero(&data, sizeof(t_split));
  while (i <= filler->map->height && get_next_line(0, &data.str) > 0)
  {
    ft_dprintf(2, "++ %s WITH LEN = %lu AT %i\n", data.str, data.len, i);
    if (!(data.array = ft_strsplit(data.str, WHITESPACES, &data.len)))
    {
      split_clear(&data);
      return (-1);
    }
    if (data.len < 2)
      continue;
    if (!(filler->map->data[i - 2] = ft_strdup(data.array[1])))
    {
      ft_tabdel((void **)filler->map->data, i);
      return (-1);
    }
    i++;
  }
  filler->map->data[i - 2] = NULL;
  return (0);
}

int read_map(char *line, t_filler *filler)
{
  if (read_map_header(line, filler) < 0)
    return (-1);
  ft_dprintf(2, "::width => %lu || height => %lu ::\n",
             filler->map->width, filler->map->height);
  if (map_init(filler) < 0)
    return (-1);
  if (read_map_body(filler) < 0)
    return (-1);
  return (0);
}
