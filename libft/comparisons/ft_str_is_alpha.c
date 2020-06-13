/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:31:47 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 13:10:15 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comparisons.h"

int		ft_str_is_alpha(const char *str)
{
	while (*str)
	{
		if (!ft_isalpha(*str))
			return (0);
		str++;
	}
	return (1);
}
