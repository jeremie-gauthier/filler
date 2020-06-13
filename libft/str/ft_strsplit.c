/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:38:37 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/11 13:27:44 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, const char *banned, size_t *len)
{
	size_t	words;
	size_t	in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (!ft_strchr(banned, *s) && in_word == 0)
		{
			in_word = 1;
			words++;
		}
		else if (ft_strchr(banned, *s))
			in_word = 0;
		s++;
	}
	if (len)
		*len = words;
	return (words);
}

char			**ft_strsplit(char const *s, const char *banned, size_t *len)
{
	size_t	i;
	size_t	lentab;
	char	**tab;

	if (!s || (lentab = count_words(s, banned, len)) == 0)
		return (NULL);
	i = 0;
	if (!(tab = (char**)malloc(sizeof(*tab) * (lentab + 1))))
		return (NULL);
	while (i < lentab)
	{
		while (ft_strchr(banned, *s))
			s++;
		if (!(tab[i] = ft_strcdup(s, banned)))
		{
			ft_tabdel((void*)tab, i);
			return (0);
		}
		while (!ft_strchr(banned, *s) && *s)
			s++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
