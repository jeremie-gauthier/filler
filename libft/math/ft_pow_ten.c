/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_ten.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:45:38 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/26 17:51:20 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow_ten(double nb, int power)
{
	int		count;

	count = 0;
	if (power < 0)
		return (0);
	while (count < power)
	{
		nb *= 10;
		count++;
	}
	return (nb);
}
