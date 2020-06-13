/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:35:28 by jergauth          #+#    #+#             */
/*   Updated: 2019/08/20 08:56:25 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && s2)
		return (ft_strdup((char*)s2));
	if (!s2 && s1)
		return (ft_strdup((char*)s1));
	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(*str) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_memcpy((void*)str, (const void*)s1, len_s1);
	ft_memcpy((void*)&str[len_s1], (const void*)s2, len_s2 + 1);
	return (str);
}
