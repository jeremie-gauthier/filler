/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:52:50 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/11 22:14:34 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(void **tab, size_t size)
{
	size_t	i;

	i = 0;
	if (tab && size > 0)
	{
		while (i < size)
		{
			if (tab[i])
				ft_memdel((void**)&tab[i]);
			i++;
		}
		free(tab);
		tab = NULL;
	}
}
