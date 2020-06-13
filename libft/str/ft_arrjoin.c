/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:09:19 by jergauth          #+#    #+#             */
/*   Updated: 2019/08/13 18:09:37 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	sum_len_words(const char **arr)
{
	size_t	sum;

	sum = 0;
	while (*arr)
	{
		sum += ft_strlen(*arr);
		arr++;
	}
	return (sum);
}

char			*ft_arrjoin(const char **arr, const int glue)
{
	char	*str;
	size_t	len;

	len = ft_arrlen((void*)arr) + sum_len_words(arr);
	if (!(str = (char*)malloc(sizeof(*str) * len)))
		return (NULL);
	while (*arr)
	{
		while (**arr)
			*str++ = *(*arr)++;
		arr++;
		*str++ = glue;
	}
	*(str - 1) = '\0';
	return (str - len);
}
