/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:46:47 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 12:53:36 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *accept)
{
	char	*tmp;

	while (*accept)
	{
		if ((tmp = ft_strchr(s, *accept)))
			return (tmp);
		accept++;
	}
	return (NULL);
}
