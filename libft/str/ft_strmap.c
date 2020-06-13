/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:36:13 by jergauth          #+#    #+#             */
/*   Updated: 2018/11/08 11:33:43 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	size_t	len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (!(newstr = (char*)malloc(sizeof(*newstr) * (len + 1))))
		return (NULL);
	while (*s)
	{
		*newstr = f(*s);
		newstr++;
		s++;
	}
	*newstr = '\0';
	return (newstr - len);
}
