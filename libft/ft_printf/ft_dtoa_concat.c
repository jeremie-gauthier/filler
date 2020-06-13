/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_concat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 18:18:18 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/27 18:18:19 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa_concat(char *s, long l, int sign)
{
	char	*whole;
	char	*tmp;

	whole = NULL;
	if (sign)
	{
		if (!(whole = ft_ltoa_base(l, 10)))
			return (NULL);
		tmp = whole;
		if (!(whole = ft_strjoin("-", whole)))
		{
			ft_strdel(&tmp);
			return (NULL);
		}
	}
	if (!(s = ft_strjoin_free((whole) ? whole : ft_ltoa_base(l, 10), s)))
		return (NULL);
	return (s);
}

char	*ft_ldtoa_concat(char *s, long long l, int sign)
{
	char	*whole;
	char	*tmp;

	whole = NULL;
	if (sign)
	{
		if (!(whole = ft_ltoa_base(l, 10)))
			return (NULL);
		tmp = whole;
		if (!(whole = ft_strjoin("-", whole)))
		{
			ft_strdel(&tmp);
			return (NULL);
		}
	}
	if (!(s = ft_strjoin_free((whole) ? whole : ft_ltoa_base(l, 10), s)))
		return (NULL);
	return (s);
}
