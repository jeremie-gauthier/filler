/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:27:24 by jergauth          #+#    #+#             */
/*   Updated: 2019/01/17 22:15:35 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cycle_detector(const t_list *list)
{
	t_list	*tortue;
	t_list	*lievre;

	if (list == NULL)
		return (0);
	tortue = (t_list*)list;
	if (tortue->next == NULL)
		return (0);
	lievre = tortue->next;
	while (lievre->next && lievre->next->next)
	{
		lievre = lievre->next->next;
		if (lievre == tortue)
			return (1);
		tortue = tortue->next;
	}
	return (0);
}
