/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_dest_row.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:51:19 by cghael            #+#    #+#             */
/*   Updated: 2019/11/08 14:51:21 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_head.h"

/*
** \brief			Free the t_dest row list in decision list.
** \param	head	Takes first node in the row.
*/

void	ft_delete_dest_row(t_dest *head)
{
	t_dest	*tmp1;
	t_dest	*tmp2;

	tmp1 = head->left;
	while (tmp1 != head)
	{
		tmp2 = tmp1->left;
		free(tmp1);
		tmp1 = tmp2;
	}
	free(tmp1);
}
