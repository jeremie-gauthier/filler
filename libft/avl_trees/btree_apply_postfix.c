/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_postfix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 01:03:29 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 01:03:40 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_postfix_lr(t_btree *root, void (*applyf)(void *))
{
	if (root && applyf)
	{
		if (root->left)
			btree_apply_postfix_lr(root->left, applyf);
		if (root->right)
			btree_apply_postfix_lr(root->right, applyf);
		if (root->data)
			applyf(root->data);
	}
}

void	btree_apply_postfix_rl(t_btree *root, void (*applyf)(void *))
{
	if (root && applyf)
	{
		if (root->right)
			btree_apply_postfix_rl(root->right, applyf);
		if (root->left)
			btree_apply_postfix_rl(root->left, applyf);
		if (root->data)
			applyf(root->data);
	}
}
