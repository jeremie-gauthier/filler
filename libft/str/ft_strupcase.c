/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:39:32 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 12:52:17 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strupcase(char *s)
{
	char	*str;

	str = s;
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
	return (s);
}
