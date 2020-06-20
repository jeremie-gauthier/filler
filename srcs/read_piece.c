/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:19:22 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/20 15:12:10 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int read_piece_header(char *line, t_filler *filler)
{
  t_split data;

  ft_bzero((void *)&data, sizeof(t_split));
  if (!(data.array = ft_strsplit(line, WHITESPACES, &data.len)))
    return (-1);
  filler->piece->height = ft_atoi(data.array[1]);
  filler->piece->width = ft_atoi(data.array[2]);
  ft_tabdel((void **)data.array, data.len);
  return (0);
}

static int read_piece_body(t_filler *filler)
{
  char *line;
  size_t i;

  i = 0;
  line = NULL;
  while (i < filler->piece->height && get_next_line(0, &line) > 0)
  {
    ft_dprintf(2, "++ %s WITH LEN = %lu AT %i\n", line, ft_strlen(line), i);
    if (!(filler->piece->data[i] = line))
    {
      ft_tabdel((void **)filler->piece->data, i);
      ft_strdel(&line);
      return (-1);
    }
    i++;
  }
  filler->piece->data[i] = NULL;
  return (0);
}

int read_piece(char *line, t_filler *filler)
{
  if (read_piece_header(line, filler) < 0)
    return (-1);
  ft_dprintf(2, ":: width => %lu || height => %lu ::\n",
             filler->piece->width, filler->piece->height);
  if (data_init(&filler->piece->data, filler->piece->height) < 0)
    return (-1);
  if (read_piece_body(filler) < 0)
    return (-1);
  return (0);
}
