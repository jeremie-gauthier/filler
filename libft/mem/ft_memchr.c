/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:29:35 by jergauth          #+#    #+#             */
/*   Updated: 2019/08/20 09:07:38 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ucps;

	ucps = (unsigned char*)s;
	while (n >= sizeof(int))
	{
		if (*ucps == c)
			return (ucps);
		if (*(ucps + 1) == c)
			return (ucps + 1);
		if (*(ucps + 2) == c)
			return (ucps + 2);
		if (*(ucps + 3) == c)
			return (ucps + 3);
		ucps += sizeof(int);
		n -= sizeof(int);
	}
	while (n--)
	{
		if (*ucps == c)
			return (ucps);
		ucps++;
	}
	return (NULL);
}
