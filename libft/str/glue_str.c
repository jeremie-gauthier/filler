/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glue_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 00:36:15 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 00:36:23 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Concatenation of two strings with slahs ('/') between them.
*/

char	*glue_str(char const *s1, char const *s2, char glue)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = malloc((len_s1 + len_s2 + 2) * sizeof(char))))
		return (NULL);
	ft_memcpy((void*)str, (void*)s1, len_s1);
	str[len_s1] = glue;
	ft_memcpy((void*)&str[len_s1 + 1], (void*)s2, len_s2 + 1);
	return (str);
}
