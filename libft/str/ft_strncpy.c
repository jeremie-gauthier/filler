/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:37:13 by jergauth          #+#    #+#             */
/*   Updated: 2018/11/07 11:37:15 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*str;

	str = dest;
	while (*src && n > 0)
	{
		*str++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*str++ = '\0';
		n--;
	}
	return (dest);
}
