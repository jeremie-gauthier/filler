/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 17:36:25 by jergauth          #+#    #+#             */
/*   Updated: 2018/12/25 17:41:20 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int start, int end)
{
	int		*tab;
	int		i;

	if (end < start)
		return (NULL);
	if (!(tab = (int*)malloc(sizeof(*tab) * (end - start))))
		return (NULL);
	i = 0;
	while (start <= end)
		tab[i++] = start++;
	return (tab);
}
