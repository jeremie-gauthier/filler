/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:19:31 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/01 17:31:06 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int is_empty_row(const char *row)
{
  return ft_strchr(row, '*') == NULL;
}

int is_empty_col(const char **array, const size_t idx_col)
{
  size_t row;

  row = 0;
  while (array[row])
  {
    if (array[row][idx_col] == '*')
      return (0);
    row++;
  }
  return (1);
}
