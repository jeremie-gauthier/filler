/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 17:55:06 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/16 17:01:40 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putnbr_base(int n, int base)
{
	if (base > 1 && base <= 16)
	{
		if (n == -2147483648)
		{
			n = 147483648;
			ft_putstr("-2");
		}
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= base)
			putnbr_base(n / base, base);
		(n % base) > 9 ? ft_putchar(n % base + 55) : ft_putchar(n % base + 48);
	}
}
