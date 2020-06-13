/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:29:48 by jergauth          #+#    #+#             */
/*   Updated: 2019/08/24 11:35:34 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned long	*lp1;
	const unsigned long	*lp2;
	const unsigned char	*cp1;
	const unsigned char	*cp2;

	lp1 = (const unsigned long*)s1;
	lp2 = (const unsigned long*)s2;
	while (*lp1 == *lp2)
	{
		lp1++;
		lp2++;
		n -= sizeof(unsigned long);
	}
	cp1 = (const unsigned char*)lp1;
	cp2 = (const unsigned char*)lp2;
	while (*cp1 == *cp2)
	{
		cp1++;
		cp2++;
		n--;
	}
	return (*cp1 - *cp2);
}
