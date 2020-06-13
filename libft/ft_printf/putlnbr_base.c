/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlnbr_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:23:31 by jergauth          #+#    #+#             */
/*   Updated: 2018/12/28 19:36:19 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putlnbr_base(long n, short base)
{
	if (base > 1 && base <= 16)
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= base)
			putlnbr_base(n / base, base);
		(n % base) > 9 ? ft_putchar(n % base + 55) : ft_putchar(n % base + 48);
	}
}
