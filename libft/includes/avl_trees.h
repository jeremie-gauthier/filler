/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_trees.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:07:26 by jergauth          #+#    #+#             */
/*   Updated: 2019/11/15 13:11:45 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREES_H
# define AVL_TREES_H

# include <stdlib.h>

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*data;
	int				height;
}					t_btree;

t_btree				*btree_create_node(void *data);
int					btree_insert_data(t_btree **root, void *x,
						int (*cmpf)(const void *, const void *));
int					btree_height(t_btree *root);
int					btree_balance_factor(t_btree *root);
void				btree_rotate_right(t_btree **root);
void				btree_rotate_left(t_btree **root);
void				btree_apply_prefix_lr(t_btree *root,
						void (*applyf)(void *));
void				btree_apply_prefix_rl(t_btree *root,
						void (*applyf)(void *));
void				btree_apply_infix_lr(t_btree *root,
						void (*applyf)(void *));
void				btree_apply_infix_rl(t_btree *root,
						void (*applyf)(void *));
void				btree_apply_postfix_lr(t_btree *root,
						void (*applyf)(void *));
void				btree_apply_postfix_rl(t_btree *root,
						void (*applyf)(void *));
void				btree_remove_node(t_btree *node);
void				*btree_search_data(t_btree *root, void *data_ref,
						int (*cmpf)(const void *, const void *));
void				btree_del(t_btree **root, int data_is_malloc);

#endif
