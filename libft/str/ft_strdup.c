/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:34:51 by jergauth          #+#    #+#             */
/*   Updated: 2019/08/20 08:48:18 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;
	size_t	len;

	len = ft_strlen(s);
	if (!(sdup = (char*)malloc(sizeof(*sdup) * (len + 1))))
		return (0);
	ft_memcpy((void*)sdup, (const void*)s, len + 1);
	return (sdup);
}
