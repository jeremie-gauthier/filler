/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:37:45 by jergauth          #+#    #+#             */
/*   Updated: 2018/11/08 18:29:40 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = 0;
	if (0 == (len = ft_strlen(s2)))
		return ((char*)s1);
	if (len > ft_strlen(s1) || len > n)
		return (0);
	while (*s1 && (n - (len - 1)) > 0)
	{
		if (*s1 == *s2)
			if (!ft_strncmp(s1, s2, len))
				return ((char*)s1);
		s1++;
		n--;
	}
	return (0);
}
