/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:30:14 by cghael            #+#    #+#             */
/*   Updated: 2019/11/04 11:01:07 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*tmp;

	if (!begin_list)
		return ;
	if (!*begin_list)
		return ;
	while (*begin_list)
	{
		free((*begin_list)->content);
		tmp = (*begin_list)->next;
		free(*begin_list);
		*begin_list = tmp;
	}
}
