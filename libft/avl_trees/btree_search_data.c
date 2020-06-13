/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:24:48 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/21 14:24:49 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_data(t_btree *root, void *data_ref,
			int (*cmpf)(const void *, const void *))
{
	if (root == NULL)
		return (NULL);
	if (cmpf(root->data, data_ref) > 0)
		return (btree_search_data(root->left, data_ref, cmpf));
	else if (cmpf(root->data, data_ref) < 0)
		return (btree_search_data(root->right, data_ref, cmpf));
	return (root->data);
}
