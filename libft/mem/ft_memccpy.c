/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:29:18 by jergauth          #+#    #+#             */
/*   Updated: 2018/11/09 11:26:11 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;

	c = (unsigned char)c;
	pdest = (unsigned char*)dest;
	psrc = (const unsigned char*)src;
	while (n--)
	{
		*pdest = *psrc;
		if (*psrc == (unsigned char)c)
			return (pdest + 1);
		pdest++;
		psrc++;
	}
	return (NULL);
}
