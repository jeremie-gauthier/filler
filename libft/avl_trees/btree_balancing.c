/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_balancing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:23:27 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 01:08:04 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		btree_balance_factor(t_btree *root)
{
	int	lh;
	int	rh;

	if (root == NULL)
		return (0);
	if (root->left == NULL)
		lh = 0;
	else
		lh = 1 + root->left->height;
	if (root->right == NULL)
		rh = 0;
	else
		rh = 1 + root->right->height;
	return (lh - rh);
}

int		btree_height(t_btree *root)
{
	int	lh;
	int	rh;

	if (root == NULL)
		return (0);
	if (root->left == NULL)
		lh = 0;
	else
		lh = 1 + root->left->height;
	if (root->right == NULL)
		rh = 0;
	else
		rh = 1 + root->right->height;
	if (lh > rh)
		return (lh);
	return (rh);
}

void	btree_rotate_left(t_btree **root)
{
	t_btree	*tmp;

	tmp = (*root)->right;
	(*root)->right = tmp->left;
	tmp->left = *root;
	(*root)->height = btree_height(*root);
	tmp->height = btree_height(tmp);
	*root = tmp;
}

void	btree_rotate_right(t_btree **root)
{
	t_btree	*tmp;

	tmp = (*root)->left;
	(*root)->left = tmp->right;
	tmp->right = *root;
	(*root)->height = btree_height(*root);
	tmp->height = btree_height(tmp);
	*root = tmp;
}
