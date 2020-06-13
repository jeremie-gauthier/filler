/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:02:31 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/21 17:11:04 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This function takes 2 malloc'ed strings.
**	It will make a strjoin with them and free them.
*/

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new;

	if (!(new = ft_strjoin(s1, s2)))
		return (NULL);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (new);
}
