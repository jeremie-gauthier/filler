/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:32:23 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 12:46:36 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *s)
{
	int		in_word;
	char	*str;

	in_word = 0;
	str = s;
	while (*str)
	{
		if (ft_isalnum(*str) && !in_word)
		{
			if (ft_islower(*str))
				*str -= 32;
			in_word = 1;
		}
		else if (ft_isupper(*str) && in_word)
			*str += 32;
		else if (!ft_isalnum(*str))
			in_word = 0;
		str++;
	}
	return (s);
}
