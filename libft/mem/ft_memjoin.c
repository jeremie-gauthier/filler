/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 19:44:07 by jergauth          #+#    #+#             */
/*   Updated: 2019/08/20 09:02:09 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*one_string_valid(const void *str, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		return (NULL);
	ptr = ft_memcpy(ptr, str, size);
	return (ptr);
}

void		*ft_memjoin(const void *first, size_t size_f, const void *second,
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
	return (ptr);
}
