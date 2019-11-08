/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tdest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:38:50 by cghael            #+#    #+#             */
/*   Updated: 2019/11/08 16:37:11 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_head.h"

/*
** \brief			Create a node for the destination list (Khnut's algo).
** \param	name	The name of the tatrimino.
** 			x		X coord of the tetrimino block.
** 			y		Y coord of the tetrimino block.
** \return	new		The new node corresponding a one tetrimino block.
*/

t_dest			*ft_create_tdest(char name, int x, int y)
{
	t_dest	*new;

	new = (t_dest*)malloc(sizeof(t_dest));
	if (!new)
		return (NULL);
	new->name = name;
	new->head = new;
	new->left = new;
	new->right = new;
	new->up = new;
	new->down = new;
	new->x = x;
	new->y = y;
	new->line = 0;
	return (new);
}
