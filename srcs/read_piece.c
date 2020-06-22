/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:19:22 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/22 19:25:57 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int read_piece_header(char *line, t_piece *piece)
{
  t_split data;

  ft_bzero((void *)&data, sizeof(t_split));
  if (!(data.array = ft_strsplit(line, WHITESPACES, &data.len)))
    return (-1);
  piece->height = ft_atoi(data.array[1]);
  piece->width = ft_atoi(data.array[2]);
  ft_tabdel((void **)data.array, data.len);
  return (0);
}

static int read_piece_body(t_piece *piece)
{
  char *line;
  int i;

  i = 0;
  line = NULL;
  while (i < piece->height && get_next_line(0, &line) > 0)
  {
    ft_dprintf(2, "++ %s WITH LEN = %lu AT %i\n", line, ft_strlen(line), i);
    if (!(piece->data[i] = line))
    {
      ft_tabdel((void **)piece->data, i);
      ft_strdel(&line);
      return (-1);
    }
    i++;
  }
  piece->data[i] = NULL;
  return (0);
}

static void set_offset(t_piece *piece)
{
  int *offset_h;
  int *offset_w;
  int row;

  offset_h = &piece->offset_height;
  offset_w = &piece->offset_width;
  while (!ft_strchr(piece->data[*offset_h], '*'))
    (*offset_h)++;
  while (*offset_w < piece->width)
  {
    row = 0;
    while (row < piece->height)
    {
      if (piece->data[row][*offset_w] == '*')
        return;
      row++;
    }
    (*offset_w)++;
  }
}

static void set_true_dims(t_piece *piece)
{
  int idx;

  idx = 0;
  while ((idx + piece->offset_height) < piece->height &&
         !is_empty_row(piece->data[idx + piece->offset_height]))
    idx++;
  piece->true_height = idx;
  idx = 0;
  while ((idx + piece->offset_width) < piece->width &&
         !is_empty_col(piece->data, idx + piece->offset_width))
    idx++;
  piece->true_width = idx;
}

int read_piece(char *line, t_filler *filler)
{
  if (read_piece_header(line, filler->piece) < 0)
    return (-1);
  ft_dprintf(2, ":: width => %lu || height => %lu ::\n",
             filler->piece->width, filler->piece->height);
  if (data_init(&filler->piece->data, filler->piece->height) < 0)
    return (-1);
  if (read_piece_body(filler->piece) < 0)
    return (-1);
  set_offset(filler->piece);
  ft_dprintf(2, "OFF Height: %i\nOFF Width: %i\n",
             filler->piece->offset_height, filler->piece->offset_width);
  set_true_dims(filler->piece);
  ft_dprintf(2, "TRUE Height: %i\nTRUE Width: %i\n",
             filler->piece->true_height, filler->piece->true_width);
  return (0);
}
