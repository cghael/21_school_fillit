/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:19:40 by cghael            #+#    #+#             */
/*   Updated: 2019/09/20 18:27:44 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*begin;

	if (!lst || !f)
		return (NULL);
	tmp = lst;
	begin = NULL;
	while (tmp)
	{
		ft_lstaddend(&begin, f(tmp));
		tmp = tmp->next;
	}
	return (begin);
}
