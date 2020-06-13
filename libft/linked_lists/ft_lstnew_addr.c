/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 13:42:50 by cmoulini          #+#    #+#             */
/*   Updated: 2019/04/19 13:42:52 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_addr(void *content)
{
	t_list	*node;

	if (!(node = (t_list*)malloc(sizeof(*node))))
		return (NULL);
	node->content = content;
	node->content_size = 0;
	node->next = NULL;
	return (node);
}
