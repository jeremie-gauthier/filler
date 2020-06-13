/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:29:26 by jergauth          #+#    #+#             */
/*   Updated: 2019/08/27 17:45:24 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long		*lpdst;
	const unsigned long	*lpsrc;
	unsigned char		*pdst;
	const unsigned char	*psrc;

	lpdst = (unsigned long*)dst;
	lpsrc = (const unsigned long*)src;
	while (n >= sizeof(unsigned long))
	{
		*lpdst++ = *lpsrc++;
		n -= sizeof(unsigned long);
	}
	if (n)
	{
		pdst = (unsigned char*)lpdst;
		psrc = (const unsigned char*)lpsrc;
		while (n--)
			*pdst++ = *psrc++;
	}
	return (dst);
}
