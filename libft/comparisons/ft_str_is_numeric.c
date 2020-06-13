/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:32:01 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 13:10:37 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comparisons.h"

int		ft_str_is_numeric(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
