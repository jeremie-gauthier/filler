/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:33:11 by jergauth          #+#    #+#             */
/*   Updated: 2018/11/07 11:33:19 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasestr(const char *s1, const char *s2)
{
	size_t	len;

	len = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	while (*s1)
	{
		if (*s1 == *s2)
			if (!ft_strncasecmp(s1, s2, len))
				return ((char *)s1);
		s1++;
	}
	return (0);
}
