/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 13:07:51 by jergauth          #+#    #+#             */
/*   Updated: 2020/06/16 13:09:34 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void split_clear(t_split *split)
{
  ft_strdel(&split->str);
  ft_tabdel((void**)split->array, split->len);
}

void filler_clear(t_filler *filler)
{
    ft_memdel((void**)&filler->map);
    ft_memdel((void**)&filler->me);
    ft_memdel((void**)&filler->opponent);
}
