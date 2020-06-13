/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:32:14 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 13:10:47 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comparisons.h"

int		ft_str_is_uppercase(const char *str)
{
	while (*str)
	{
		if (!ft_isupper(*str))
			return (0);
		str++;
	}
	return (1);
}
