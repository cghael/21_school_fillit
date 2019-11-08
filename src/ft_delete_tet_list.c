/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_tet_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:44:16 by cghael            #+#    #+#             */
/*   Updated: 2019/11/08 14:44:19 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_head.h"

/*
** \brief				Free the t_tet list (list for income tetriminos).
** \param	begin_list	Takes first node in the list.
*/

void		ft_delete_tet_list(t_tet *begin_list)
{
	t_tet	*tmp;

	if (!begin_list)
		return ;
	while (begin_list)
	{
		tmp = begin_list->next;
		free(begin_list);
		begin_list = tmp;
	}
}
