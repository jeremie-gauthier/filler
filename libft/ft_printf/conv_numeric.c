/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_numeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:07:07 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/26 13:07:09 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	clean_quit(char **conv, int ret)
{
	ft_strdel(conv);
	return (ret);
}

/*
**	Do a conversion with the flags h, hh, l or ll.
**	Due to va_arg, h (short) and hh (char) have to be treated as int.
**	There is only a difference for long or long long when the nb is
**	signed or unsigned.
*/

static char	*conv_w_flag(t_flags *fl, va_list ap)
{
	if (ft_strchr(INT_CONV, fl->c))
	{
		if (fl->ll == 1)
			return (ft_lltoa_base(va_arg(ap, long long), fl->base));
		else if (fl->l == 1)
			return (ft_ltoa_base(va_arg(ap, long), fl->base));
		else if (fl->hh == 1)
			return (ft_itoa_base((char)va_arg(ap, int), fl->base));
		else if (fl->h == 1)
			return (ft_itoa_base((short)va_arg(ap, int), fl->base));
	}
	else if (ft_strchr(UINT_CONV, fl->c))
	{
		if (fl->ll == 1)
			return (ft_ulltoa_base(va_arg(ap, unsigned long long), fl->base));
		else if (fl->l == 1)
			return (ft_ultoa_base(va_arg(ap, unsigned long), fl->base));
		else if (fl->hh == 1)
			return (ft_itoa_base((unsigned char)va_arg(ap, int), fl->base));
		else if (fl->h == 1)
			return (ft_itoa_base((unsigned short)va_arg(ap, int), fl->base));
	}
	return (NULL);
}

/*
**	This function do all numerical (diouxXb) conversions.
*/

int			ft_conv_numeric(t_flags *fl, t_buf *buf, va_list ap)
{
	char	*conv;
	size_t	len;

	if (fl->l | fl->ll | fl->h | fl->hh)
		conv = conv_w_flag(fl, ap);
	else if (ft_strchr(INT_CONV, fl->c))
		conv = ft_itoa(va_arg(ap, int));
	else
		conv = ft_uitoa_base(va_arg(ap, unsigned int), fl->base);
	if (conv == NULL)
		return (clean_quit(&conv, 0));
	if (!(ft_format_flag(fl, &conv)))
		return (clean_quit(&conv, 0));
	if (fl->c == 'x')
		conv = ft_strlowcase(conv);
	len = ft_strlen(conv);
	if (!(buf->str = ft_memjoin_free(buf->str, buf->len, conv, len)))
		return (clean_quit(&conv, 0));
	buf->len += len;
	return (1);
}
