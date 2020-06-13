/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:27:46 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 13:10:23 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comparisons.h"

int	ft_str_is_alnum(char *str)
{
	while (*str)
	{
		if (!ft_isalnum(*str))
			return (0);
		str++;
	}
	return (1);
}
