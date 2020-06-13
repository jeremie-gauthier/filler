/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:08:35 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/04 19:24:57 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		clean_quit(char **tmp, char **color, int ret)
{
	ft_strdel(tmp);
	ft_strdel(color);
	return (ret);
}

static char		*get_ansi_bg_color_code(char *color)
{
	if (ft_strcasecmp(color, "BG_BLACK") == 0)
		return (BG_BLACK);
	if (ft_strcasecmp(color, "BG_RED") == 0)
		return (BG_RED);
	if (ft_strcasecmp(color, "BG_GREEN") == 0)
		return (BG_GREEN);
	if (ft_strcasecmp(color, "BG_YELLOW") == 0)
		return (BG_YELLOW);
	if (ft_strcasecmp(color, "BG_BLUE") == 0)
		return (BG_BLUE);
	if (ft_strcasecmp(color, "BG_MAGENTA") == 0)
		return (BG_MAGENTA);
	if (ft_strcasecmp(color, "BG_CYAN") == 0)
		return (BG_CYAN);
	if (ft_strcasecmp(color, "CLEAR") == 0)
		return (CLEAR);
	if (ft_strcasecmp(color, "RESET") == 0)
		return (RESET);
	return (NULL);
}

static char		*get_ansi_color_code(char *color)
{
	if (ft_strcasecmp(color, "ITALIC") == 0)
		return (ITALIC);
	if (ft_strcasecmp(color, "BOLD") == 0)
		return (BOLD);
	if (ft_strcasecmp(color, "UNDERLINE") == 0)
		return (UNDERLINE);
	if (ft_strcasecmp(color, "REVERSE") == 0)
		return (REVERSE);
	if (ft_strcasecmp(color, "BLACK") == 0)
		return (BLACK);
	if (ft_strcasecmp(color, "RED") == 0)
		return (RED);
	if (ft_strcasecmp(color, "GREEN") == 0)
		return (GREEN);
	if (ft_strcasecmp(color, "YELLOW") == 0)
		return (YELLOW);
	if (ft_strcasecmp(color, "BLUE") == 0)
		return (BLUE);
	if (ft_strcasecmp(color, "MAGENTA") == 0)
		return (MAGENTA);
	if (ft_strcasecmp(color, "CYAN") == 0)
		return (CYAN);
	if (ft_strcasecmp(color, "WHITE") == 0)
		return (WHITE);
	return (get_ansi_bg_color_code(color));
}

static int		fail_sequence(t_buf *buf, char *color)
{
	char	*tmp;

	tmp = (char*)buf->str;
	if (!(buf->str = ft_memjoin(buf->str, buf->len, "{", 1)))
	{
		buf->str = tmp;
		return (clean_quit(NULL, &color, 1));
	}
	buf->len++;
	return (clean_quit(&tmp, &color, 1));
}

/*
**	This functions aims to change the color of the text when
**	a special keyword is found.
**	It takes 3 arguments:
**	1 - A double pointer on the format string (from ft_printf), to increment
**		the address of the pointer.
**	2 - A double pointer on the str string (the return string of ft_printf)
**		to change its value.
**	3 - A pointer on int (retain). This is the len of the color which is added
**		and must be deduce to the return value of ft_printf.
*/

int				ft_parse_color(const char **format, t_buf *buf)
{
	char	*tmp;
	char	*color;
	char	*ansi_color_code;
	size_t	len;

	color = NULL;
	tmp = ft_strpbrk(*format, "}%");
	if (tmp == NULL || *tmp == '%')
		return (fail_sequence(buf, color));
	(*format)++;
	len = tmp - *format;
	if (!(color = ft_strndup(*format, len)))
		return (0);
	if (!(ansi_color_code = get_ansi_color_code(color)))
		return (fail_sequence(buf, color));
	tmp = buf->str;
	if (!(buf->str = ft_memjoin(buf->str, buf->len, ansi_color_code,
				ft_strlen(ansi_color_code))))
		return (clean_quit(NULL, &color, 0));
	buf->len += ft_strlen(ansi_color_code);
	*format += len + 1;
	return (clean_quit(&tmp, &color, 1));
}
