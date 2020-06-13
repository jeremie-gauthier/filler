/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 00:34:03 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/19 21:25:09 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Create a new string resulting of the replacement
**	of `substr` in `str` with `replacement`.
*/

char		*replace_substr(const char *str, const char *substr,
				const char *replacement)
{
	size_t	len_str;
	size_t	len_substr;
	size_t	len_replcmt;
	size_t	i;
	char	*ret;

	len_substr = ft_strlen(substr);
	len_str = ft_strlen(str) - len_substr;
	len_replcmt = ft_strlen(replacement);
	if (!(ret = malloc((len_str + len_replcmt + 1) * sizeof(char))))
		return (NULL);
	i = ft_strstr(str, substr) - str;
	ft_memcpy(ret, str, i);
	ft_memcpy(&ret[i], replacement, len_replcmt);
	str += len_substr + i;
	i += len_replcmt;
	ft_memcpy(&ret[i], str, ft_strlen(str) + 1);
	return (ret);
}
