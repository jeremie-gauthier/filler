/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:10:32 by jergauth          #+#    #+#             */
/*   Updated: 2019/08/26 20:59:26 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		g_buffer[OUTBUF];
static size_t	g_idx = 0;

void	bufferize(const char *src, const size_t len)
{
	if (g_idx + len >= OUTBUF)
	{
		write(1, g_buffer, g_idx);
		g_idx = 0;
	}
	ft_memcpy((void*)&g_buffer[g_idx], (void*)src, len);
	g_idx += len;
}

void	print_buffer(void)
{
	write(1, g_buffer, g_idx);
	g_idx = 0;
}
