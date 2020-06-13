/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:24:10 by jergauth          #+#    #+#             */
/*   Updated: 2019/08/03 20:17:20 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_del(t_btree **root, int data_is_malloc)
{
	if (root && *root)
	{
		if ((*root)->left)
			btree_del(&(*root)->left, data_is_malloc);
		if ((*root)->right)
			btree_del(&(*root)->right, data_is_malloc);
		if (data_is_malloc == 1)
			ft_memdel(&(*root)->data);
		ft_memdel((void**)root);
	}
}
