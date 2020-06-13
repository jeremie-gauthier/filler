/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 01:03:59 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 01:04:13 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_prefix_lr(t_btree *root, void (*applyf)(void *))
{
	if (root && applyf)
	{
		if (root->data)
			applyf(root->data);
		if (root->left)
			btree_apply_prefix_lr(root->left, applyf);
		if (root->right)
			btree_apply_prefix_lr(root->right, applyf);
	}
}

void	btree_apply_prefix_rl(t_btree *root, void (*applyf)(void *))
{
	if (root && applyf)
	{
		if (root->data)
			applyf(root->data);
		if (root->right)
			btree_apply_prefix_rl(root->right, applyf);
		if (root->left)
			btree_apply_prefix_rl(root->left, applyf);
	}
}
