/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uncover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:02:28 by cghael            #+#    #+#             */
/*   Updated: 2019/11/08 14:03:59 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_head.h"

/*
** \brief			Function uncovers target queue of rows.
** \param	queue	List that contains all covered rows.
*/

void			ft_uncover(t_list *queue)
{
	t_dest	*row;
	t_dest	*hrow;

	while (queue)
	{
		hrow = (t_dest*)(queue->content);
		row = hrow;
		while (row->right != hrow)
		{
			(row->up)->down = row;
			(row->down)->up = row;
			row = row->right;
		}
		(row->up)->down = row;
		(row->down)->up = row;
		queue = queue->next;
	}
}
