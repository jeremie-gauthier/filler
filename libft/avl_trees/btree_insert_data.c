/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:24:22 by jergauth          #+#    #+#             */
/*   Updated: 2019/08/02 21:02:16 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Implementation of AVL Trees insertion
*/

static void	insert_right(t_btree **root, void *x,
				int (*cmpf)(const void *, const void *))
{
	if (cmpf(x, (*root)->right->data) >= 0)
		btree_rotate_left(root);
	else
	{
		btree_rotate_right(&(*root)->right);
		btree_rotate_left(root);
	}
}

static void	insert_left(t_btree **root, void *x,
				int (*cmpf)(const void *, const void *))
{
	if (cmpf(x, (*root)->left->data) < 0)
		btree_rotate_right(root);
	else
	{
		btree_rotate_left(&(*root)->left);
		btree_rotate_right(root);
	}
}

static int	btree_recurs_node(t_btree **root, void *x,
				int (*cmpf)(const void *, const void *))
{
	if (cmpf(x, (*root)->data) >= 0)
	{
		if (!(btree_insert_data(&(*root)->right, x, cmpf)))
			return (0);
		if (btree_balance_factor(*root) == -2)
			insert_right(root, x, cmpf);
	}
	else
	{
		if (!(btree_insert_data(&(*root)->left, x, cmpf)))
			return (0);
		if (btree_balance_factor(*root) == 2)
			insert_left(root, x, cmpf);
	}
	(*root)->height = btree_height(*root);
	return (1);
}

int			btree_insert_data(t_btree **root, void *x,
				int (*cmpf)(const void *, const void *))
{
	if (cmpf == NULL || x == NULL)
		return (0);
	if (*root == NULL)
	{
		if (!(*root = btree_create_node(x)))
			return (0);
	}
	else
	{
		if (!(btree_recurs_node(root, x, cmpf)))
			return (0);
	}
	return (1);
}
