/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 13:41:57 by cmoulini          #+#    #+#             */
/*   Updated: 2019/04/19 13:41:59 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpop(t_list **head)
{
	t_list	*tmp;

	if (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->content = NULL;
		tmp->content_size = 0;
		tmp->next = NULL;
		ft_memdel((void*)tmp);
	}
}
