/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:13:56 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 12:51:45 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

void	ft_bzero(void *s, size_t n)
{
	long	*str;
	char	*str_2;

	str = (long*)s;
	while ((n >= sizeof(long)))
	{
		*str++ = 0;
		n -= sizeof(long);
	}
	str_2 = (char*)str;
	while (n > 0)
	{
		*str_2++ = 0;
		n--;
	}
}
