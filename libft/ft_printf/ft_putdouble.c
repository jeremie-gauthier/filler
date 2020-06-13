/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 12:23:04 by jergauth          #+#    #+#             */
/*   Updated: 2018/12/29 12:08:15 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_decimal_part(char *s, unsigned short p)
{
	unsigned short	ret;
	unsigned short	ind;

	s[p] = '\0';
	ret = 1;
	while (1)
	{
		ind = p - (ret + 1);
		if (s[p - ret] >= '5')
		{
			if (s[ind] + 1 != 58)
			{
				s[ind] += 1;
				break ;
			}
			else if (s[ind] + 1 == 58)
				s[ind] = '0';
			ret++;
		}
		else
			break ;
	}
	s[p - 1] = '\0';
	ft_putstr(s);
	ft_strdel(&s);
}

void			ft_putdouble(double d, unsigned short precision)
{
	long			l;
	unsigned short	p;
	char			*s;

	if ((s = (char*)malloc(sizeof(*s) * (precision + 2))))
	{
		if (d < 0)
			ft_putchar('-');
		l = (long)d;
		putlnbr_base(l, 10);
		d -= l;
		if (precision > 0)
		{
			ft_putchar('.');
			p = 0;
			while (p < precision + 1)
			{
				d *= 10;
				l = (long)d;
				s[p++] = l + 48;
				d -= l;
			}
			print_decimal_part(s, p);
		}
	}
}
