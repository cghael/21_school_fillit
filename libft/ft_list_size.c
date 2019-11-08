/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:43:18 by cghael            #+#    #+#             */
/*   Updated: 2019/09/19 17:38:24 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_list_size(t_list *begin_list)
{
	size_t	counter;
	t_list	*tmp;

	if (!begin_list)
		return (0);
	else
	{
		tmp = begin_list;
		counter = 1;
		while (begin_list->next)
		{
			begin_list = begin_list->next;
			counter++;
		}
	}
	return (counter);
}
