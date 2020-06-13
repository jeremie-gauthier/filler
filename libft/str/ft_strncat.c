/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:36:39 by jergauth          #+#    #+#             */
/*   Updated: 2018/11/07 11:40:48 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*iter;

	iter = dest;
	while (*iter)
		iter++;
	while (n-- > 0 && *src)
	{
		*iter = *src;
		iter++;
		src++;
	}
	*iter = '\0';
	return (dest);
}
