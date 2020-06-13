/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:41:40 by jergauth          #+#    #+#             */
/*   Updated: 2019/08/20 10:09:18 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Capital letters "DIOU" are treated as "diou" with 'l' (long) flag.
*/

void		redirection_conversion(t_flags *fl)
{
	fl->c = ft_tolower(fl->c);
	add_flag('l', fl);
}

/*
**	Redirect the conversion to the appropriate function
*/

int			conversion(t_flags *fl, t_buf *buf, va_list ap)
{
	if (fl->c == 'C' || fl->c == 'S' || ((fl->l == 1
				&& (fl->c == 's' || fl->c == 'c'))))
		return (0);
	else if (ft_memchr(NUMERIC_CONV, fl->c, NB_NUM_CONV))
		return (ft_conv_numeric(fl, buf, ap));
	else if (ft_strchr(CHAR_CONV, fl->c))
		return (ft_conv_str(fl, buf, ap));
	else if (fl->c == 'f')
		return (ft_conv_double(fl, buf, ap));
	else if (fl->c == 'p')
		return (ft_conv_ptr(fl, buf, ap));
	else
		return (0);
	return (1);
}
