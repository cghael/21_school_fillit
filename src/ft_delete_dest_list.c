/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_dest_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <cghael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:11:14 by cghael            #+#    #+#             */
/*   Updated: 2019/11/08 14:50:36 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_head.h"

/*
** \brief				Free the t_dest list starting at the upper right end.
** \param	begin_list	Takes first node in the list.
*/

void		ft_delete_dest_list(t_dest **root)
{
	t_dest	*tmp1;
	t_dest	*tmp2;

	if (!root || !*root)
		return ;
	tmp1 = (*root)->up;
	while (tmp1 != *root)
	{
		tmp2 = tmp1->up;
		ft_delete_dest_row(tmp1);
		tmp1 = tmp2;
	}
	tmp1 = (*root)->left;
	while (tmp1 != *root)
	{
		tmp2 = tmp1->left;
		free(tmp1);
		tmp1 = tmp2;
	}
	free(*root);
	*root = NULL;
}
