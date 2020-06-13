/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 01:02:40 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 01:02:56 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_infix_lr(t_btree *root, void (*applyf)(void *))
{
	if (root && applyf)
	{
		if (root->left)
			btree_apply_infix_lr(root->left, applyf);
		if (root->data)
			applyf(root->data);
		if (root->right)
			btree_apply_infix_lr(root->right, applyf);
	}
}

void	btree_apply_infix_rl(t_btree *root, void (*applyf)(void *))
{
	if (root && applyf)
	{
		if (root->right)
			btree_apply_infix_rl(root->right, applyf);
		if (root->data)
			applyf(root->data);
		if (root->left)
			btree_apply_infix_rl(root->left, applyf);
	}
}
