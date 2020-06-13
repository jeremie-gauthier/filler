/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:14:04 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/26 15:14:05 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Format diese (sharp #), will prefix a non decimal base numeric conversion.
**	It will append a dot at the end of a floating conversion.
**	HEXADECIMAL	=>	0x or 0X
**	OCTAL		=>	0
**	BINARY		=>	0b
**	FLOAT CONVS	=>	.
*/

int			ft_format_diese(t_flags *fl, char **conv)
{
	char	*tmp;

	tmp = *conv;
	if ((fl->dz && ((fl->c == 'x') | (fl->c == 'X') | (fl->c == 'b')
			| ((fl->c == 'o') & (*conv[0] != '0'))
				| ((fl->c == 'f') & (fl->prc == 0)))) || (fl->c == 'p'))
	{
		if (fl->c == 'x' || fl->c == 'X' || fl->c == 'p')
			if (!(*conv = ft_strjoin("0X", *conv)))
				return (0);
		if (fl->c == 'b')
			if (!(*conv = ft_strjoin("0b", *conv)))
				return (0);
		if (fl->c == 'o')
			if (!(*conv = ft_strjoin("0", *conv)))
				return (0);
		if (fl->c == 'f')
			if (!(*conv = ft_strjoin(*conv, ".")))
				return (0);
		fl->dz = 0;
		ft_strdel(&tmp);
	}
	return (1);
}

static int	ft_string_prc(t_flags *fl, char **conv)
{
	char	*tmp;

	tmp = *conv;
	if (!(*conv = ft_strndup(*conv, fl->prc)))
		return (0);
	ft_strdel(&tmp);
	return (1);
}

static int	ft_numeric_prc(t_flags *fl, char **conv, int len)
{
	char	*substr;

	len = fl->prc - len;
	if (*conv[0] == '-')
	{
		*conv[0] = '0';
		if (!(substr = (char*)ft_memalloc(len + 1)))
			return (0);
		substr = ft_memset((void*)substr, '0', len);
		substr[0] = '-';
	}
	else
	{
		if (!(substr = (char*)ft_memalloc(len + 1)))
			return (0);
		substr = ft_memset((void*)substr, '0', len);
	}
	if (!(*conv = ft_strjoin_free(substr, *conv)))
	{
		ft_strdel(&substr);
		return (0);
	}
	return (1);
}

int			ft_zero_value_numeric_conv_zero_prc(t_flags *fl, char **conv)
{
	ft_strdel(conv);
	if (fl->dz && (fl->c == 'o' || fl->c == 'p'))
	{
		if (fl->c == 'o')
			if (!(*conv = ft_strdup("0")))
				return (0);
		if (fl->c == 'p')
			if (!(*conv = ft_strdup("0x")))
				return (0);
		if (fl->c == 'b')
			if (!(*conv = ft_strdup("0b")))
				return (0);
	}
	else if (!(*conv = ft_strdup("\0")))
		return (0);
	fl->dz = 0;
	return (1);
}

/*
**	Precision of the field :
**	---------------------------------------------------
**	STRING		=>	Print at most 'fl->prc' characters.
**		* May be truncated if len(string) > precision.
**	NUMERICS	=>	Print at least 'fl->prc' characters.
**		* Padded with '0' if len(numeric) < precision.
**	---------------------------------------------------
**	The sign '-' is not counted in the len in case of a numeric conversion.
*/

int			ft_format_prc(t_flags *fl, char **conv, int *len)
{
	*len = ft_strlen(*conv);
	if (fl->prc < *len && fl->c == 's')
	{
		if (!(ft_string_prc(fl, conv)))
			return (0);
	}
	else if (fl->prc >= *len && (ft_strchr(INT_CONV, fl->c)
				|| ft_strchr(UINT_CONV, fl->c) || fl->c == 'p'))
	{
		if (*conv[0] == '-')
			(*len)--;
		if (!(ft_numeric_prc(fl, conv, *len)))
			return (0);
	}
	*len = ft_strlen(*conv);
	return (1);
}
