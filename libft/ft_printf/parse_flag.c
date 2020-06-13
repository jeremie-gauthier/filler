/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:08:02 by jergauth          #+#    #+#             */
/*   Updated: 2019/08/24 14:47:08 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	clean_quit(t_flags **fl, int ret)
{
	ft_memdel((void**)fl);
	return (ret);
}

/*
**	Add the numeric values (precision and padding) to the struct.
*/

static void	add_numeric_flags(va_list ap, t_flags *fl, const char **format)
{
	if (**format == '.')
	{
		(*format)++;
		fl->prc = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	if (ft_isdigit(**format) && **format != '0')
	{
		fl->pad = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	if (**format == '*')
	{
		(*format)++;
		fl->pad = va_arg(ap, int);
	}
}

static void	set_base_conv(t_flags *fl)
{
	if (fl->c == 'b')
		fl->base = 2;
	else if (fl->c == 'o')
		fl->base = 8;
	else if (fl->c == 'x' || fl->c == 'X')
		fl->base = 16;
}

/*
**	Function that parse from '%' to a conversion character ["cspdiouxXb"] and
**	fill the struct.
*/

int			parse_flags(const char **form, t_buf *buf, va_list ap)
{
	t_flags	*fl;

	if (!(fl = init_flags()))
		return (0);
	(*form)++;
	while (**form && ft_instr(**form, ALL_FLAGS))
	{
		add_flag(**form, fl);
		if (ft_strchr(".*", **form) || (ft_isdigit(**form) && **form != '0'))
			add_numeric_flags(ap, fl, form);
		else
			(*form)++;
	}
	if (ft_instr(**form, ALL_CONV) || ft_instr(**form, REDIRECT))
	{
		fl->c = **form;
		if (ft_instr(**form, REDIRECT))
			redirection_conversion(fl);
		set_base_conv(fl);
		if (!(conversion(fl, buf, ap)))
			return (clean_quit(&fl, 0));
		if (**form)
			(*form)++;
	}
	return (clean_quit(&fl, 1));
}
