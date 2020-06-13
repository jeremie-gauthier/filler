/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:22:21 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/30 17:22:22 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	clean_quit(t_buf *buf, int ret)
{
	size_t	len;

	len = 0;
	if (buf != NULL)
	{
		len = buf->len;
		ft_memdel(&buf->str);
		ft_memdel((void*)&buf);
	}
	if (ret == 0)
		return (-1);
	return (len);
}

/*
**	Format a string and print it to stdout, no variable args.
**	buf		=	the buffer which will be printed at the end.
*/

int			ft_vprintf(const char *format, va_list ap)
{
	t_buf	*buf;

	if (!(buf = init_buf()))
		return (clean_quit(buf, 0));
	while (*format)
	{
		if (*format && *format != '%' && *format != '{')
		{
			if (parse_format(&format, buf) <= 0)
			{
				write(1, buf->str, buf->len);
				return (clean_quit(buf, 1));
			}
		}
		if (*format && *format == '{')
			if (!(ft_parse_color(&format, buf)))
				return (clean_quit(buf, 0));
		if (*format && *format == '%')
			if (!(parse_flags(&format, buf, ap)))
				return (clean_quit(buf, 0));
	}
	write(1, buf->str, buf->len);
	return (clean_quit(buf, 1));
}

/*
**	Format a string and store it in char *s, no variable args.
**	buf		=	the buffer which will be printed at the end.
*/

int			ft_vsprintf(char *s, const char *format, va_list ap)
{
	t_buf	*buf;

	if (!(buf = init_buf()))
		return (clean_quit(buf, 0));
	while (*format)
	{
		if (*format && *format != '%' && *format != '{')
		{
			if (parse_format(&format, buf) <= 0)
			{
				s = ft_strncpy_safe(s, buf->str, buf->len + 1);
				return (clean_quit(buf, 1));
			}
		}
		if (*format && *format == '{')
			if (!(ft_parse_color(&format, buf)))
				return (clean_quit(buf, 0));
		if (*format && *format == '%')
			if (!(parse_flags(&format, buf, ap)))
				return (clean_quit(buf, 0));
	}
	s = ft_strncpy_safe(s, buf->str, buf->len + 1);
	return (clean_quit(buf, 1));
}

/*
**	Format a string and store the size first chars in char *s, no variable args.
**	buf		=	the buffer which will be copied in *s at the end.
*/

int			ft_vsnprintf(char *s, size_t size, const char *format, va_list ap)
{
	t_buf	*buf;

	if (!(buf = init_buf()))
		return (clean_quit(buf, 0));
	while (*format)
	{
		if (*format && *format != '%' && *format != '{')
		{
			if (parse_format(&format, buf) <= 0)
			{
				s = ft_strncpy_safe(s, buf->str, size);
				return (clean_quit(buf, 1));
			}
		}
		if (*format && *format == '{')
			if (!(ft_parse_color(&format, buf)))
				return (clean_quit(buf, 0));
		if (*format && *format == '%')
			if (!(parse_flags(&format, buf, ap)))
				return (clean_quit(buf, 0));
	}
	s = ft_strncpy_safe(s, buf->str, size);
	return (clean_quit(buf, 1));
}

/*
**	Format a string and print it in fd, no variable args.
**	buf		=	the buffer which will be copied in the fd at the end.
*/

int			ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_buf	*buf;

	if (!(buf = init_buf()))
		return (clean_quit(buf, 0));
	while (*format)
	{
		if (*format && *format != '%' && *format != '{')
		{
			if (parse_format(&format, buf) <= 0)
			{
				write(fd, buf->str, buf->len);
				return (clean_quit(buf, 1));
			}
		}
		if (*format && *format == '{')
			if (!(ft_parse_color(&format, buf)))
				return (clean_quit(buf, 0));
		if (*format && *format == '%')
			if (!(parse_flags(&format, buf, ap)))
				return (clean_quit(buf, 0));
	}
	write(fd, buf->str, buf->len);
	return (clean_quit(buf, 1));
}
