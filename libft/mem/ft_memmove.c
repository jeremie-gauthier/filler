/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:30:08 by jergauth          #+#    #+#             */
/*   Updated: 2018/11/07 18:46:52 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	pdst = (unsigned char*)dst;
	psrc = (const unsigned char*)src;
	if (dst == src || !n)
		return (dst);
	if (src > dst)
		while (n--)
			*pdst++ = *psrc++;
	else
		while (n--)
			pdst[n] = psrc[n];
	return (dst);
}
