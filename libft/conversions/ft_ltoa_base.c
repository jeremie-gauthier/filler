/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:41:41 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 12:37:28 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa_base(long nb, short base)
{
	char	*str;
	int		len;
	int		sign;
	long	n;

	if (base <= 1 || base > 16)
		return (NULL);
	if (nb < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	sign = (nb < 0 ? 1 : 0);
	len = sign + 1;
	nb = (sign == 1 ? -nb : nb);
	n = nb;
	while ((n /= base) > 0)
		len++;
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (nb % base > 9) ? (nb % base) + 55 : (nb % base) + 48;
		nb /= base;
	}
	(sign == 1) ? str[0] = '-' : 0;
	return (str);
}
