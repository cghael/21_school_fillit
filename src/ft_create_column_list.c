/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_column_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:05:16 by cghael            #+#    #+#             */
/*   Updated: 2019/11/08 14:49:49 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file contains functions, that create destination list.
*/

#include "fillit_head.h"

/*
** \brief			Add new tdest node to the list at the end.
** \param	new		The new tdest node.
** 			begin	The begining of the list (left colomn of the dest list).
** \return	begin
*/

static t_dest	*ft_add_new_column_list_right(t_dest *new, t_dest *begin)
{
	t_dest	*tmp;

	tmp = begin;
	if (tmp)
	{
		while (tmp->right != begin)
			tmp = tmp->right;
		tmp->right = new;
		new->left = tmp;
		new->right = begin;
		begin->left = new;
	}
	else
		begin->right = new;
	return (begin);
}

/*
** \brief			Creates fist row for the destination list.
** \param	n		The side of the square.
** 			begin	The begining of the list (root in this case).
** \return	begin
*/

t_dest			*ft_create_column_list(int n, t_dest *begin)
{
	int		x;
	int		y;
	t_dest	*new;

	if (!begin)
		return (NULL);
	y = 0;
	while (y < n)
	{
		x = 0;
		while (x < n)
		{
			if (!(new = ft_create_tdest('@', x, y)))
			{
				ft_delete_dest_row(begin);
				return (NULL);
			}
			begin = ft_add_new_column_list_right(new, begin);
			x++;
		}
		y++;
	}
	return (begin);
}
