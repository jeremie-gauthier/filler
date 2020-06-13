/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:30:55 by jergauth          #+#    #+#             */
/*   Updated: 2018/11/12 12:37:41 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	char	l;

	if (!(c & 0x80))
		write(fd, &c, 1);
	else
	{
		l = ((unsigned char)c <= 191 ? 0xC2 : 0xC3);
		l = (char)(0xc2 | ((unsigned char)l));
		write(fd, &l, 1);
		l = (char)(0xBF & c);
		write(fd, &l, 1);
	}
}
