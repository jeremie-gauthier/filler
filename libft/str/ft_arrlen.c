/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:32:25 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 12:41:36 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

/*
**	Return the len of the upper dimension of a NULL-terminated 2D array.
*/

size_t	ft_arrlen(void **arr)
{
	size_t	len;

	len = 0;
	while (*arr)
	{
		len++;
		arr++;
	}
	return (len);
}
