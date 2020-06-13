/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:37:23 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 12:56:14 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*sdup;
	size_t	i;

	i = 0;
	if (!(sdup = (char*)malloc(sizeof(*sdup) * (n + 1))))
		return (NULL);
	ft_memcpy((void*)sdup, (const void*)s, n);
	sdup[n] = '\0';
	return (sdup);
}
