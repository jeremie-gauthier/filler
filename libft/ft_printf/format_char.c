/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:13:35 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/30 16:13:36 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	clean_quit(char **conv, char **substr, int ret)
{
	ft_strdel(conv);
	ft_strdel(substr);
	return (ret);
}

static int	ft_conv_char_w_padding(t_flags *fl, t_buf *buf, char c)
{
	char	*conv;
	void	*tmp;

	if (!(conv = ft_memalloc(fl->pad - 1)))
		return (0);
	ft_memset((void*)conv, (fl->f0 == 1 && fl->mo == 0) ? '0' : ' ',
				fl->pad - 1);
	tmp = conv;
	if (fl->mo == 0)
	{
		if (!(conv = ft_memjoin((void*)conv, fl->pad - 1, &c, 1)))
			return (clean_quit(&conv, NULL, 0));
	}
	else
	{
		if (!(conv = ft_memjoin(&c, 1, (void*)conv, fl->pad - 1)))
			return (clean_quit(&conv, NULL, 0));
	}
	ft_memdel(&tmp);
	if (!(buf->str = ft_memjoin_free(buf->str, buf->len, (void*)conv, fl->pad)))
		return (clean_quit(&conv, NULL, 0));
	buf->len += fl->pad;
	return (1);
}

int			ft_format_char(t_flags *fl, t_buf *buf, unsigned char c)
{
	char	*tmp;

	tmp = NULL;
	if (fl->pad > 1)
	{
		if (!(ft_conv_char_w_padding(fl, buf, c)))
			return (0);
	}
	else
	{
		tmp = buf->str;
		if (!(buf->str = ft_memjoin(buf->str, buf->len, &c, 1)))
			return (0);
		ft_strdel(&tmp);
		buf->len++;
	}
	return (1);
}

static int	ft_putspaces_to_str(t_flags *fl, char **conv, int len, t_buf *buf)
{
	char	*substr;
	int		len_pad;

	if ((len_pad = fl->pad - len) > 0)
	{
		if (!(substr = (char*)ft_memalloc(len_pad)))
			return (0);
		substr = ft_memset((void*)substr,
				(fl->mo == 0 && fl->f0 == 1) ? '0' : ' ', len_pad);
		if (fl->mo == 1)
		{
			if (!(*conv = ft_memjoin_free(*conv, len, substr, len_pad)))
				return (clean_quit(NULL, &substr, 0));
		}
		else
		{
			if (!(*conv = ft_memjoin_free(substr, len_pad, *conv, len)))
				return (clean_quit(NULL, &substr, 0));
		}
	}
	if (!(buf->str = ft_memjoin_free(buf->str, buf->len, *conv,
				(len_pad > 0) ? fl->pad : len)))
		return (clean_quit(conv, NULL, 0));
	buf->len += (len_pad > 0) ? len + len_pad : len;
	return (1);
}

int			ft_format_str(t_flags *fl, char **conv, int len, t_buf *buf)
{
	if (fl->prc != -1 && fl->prc < len)
	{
		if (!(ft_format_prc(fl, conv, &len)))
			return (0);
	}
	if (fl->pad != -1)
	{
		if (!(ft_putspaces_to_str(fl, conv, len, buf)))
			return (0);
		return (1);
	}
	if (!(buf->str = ft_memjoin_free(buf->str, buf->len, *conv, len)))
		return (clean_quit(conv, NULL, 0));
	buf->len += len;
	return (1);
}
