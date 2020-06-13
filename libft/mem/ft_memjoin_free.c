/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:08:27 by jergauth          #+#    #+#             */
/*   Updated: 2019/08/20 09:01:01 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*one_string_valid(void *str, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		return (NULL);
	ptr = ft_memcpy(ptr, str, size);
	ft_memdel(&str);
	return (ptr);
}

/*
**	This function is supposed to be used with 2 malloc'ed strings in params
*/

void		*ft_memjoin_free(void *first, size_t size_f, void *second,
				size_t size_s)
{
	void	*ptr;

	if (first == NULL && second == NULL)
		return (NULL);
	if (first != NULL && second == NULL)
		return (one_string_valid(first, size_f));
	if (first == NULL && second != NULL)
		return (one_string_valid(second, size_s));
	if (!(ptr = malloc(size_f + size_s)))
		return (NULL);
	ft_memcpy(ptr, first, size_f);
	ft_memcpy(ptr + size_f, second, size_s);
	ft_memdel(&first);
	ft_memdel(&second);
	return (ptr);
}
