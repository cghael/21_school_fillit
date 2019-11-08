/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:13:50 by cghael            #+#    #+#             */
/*   Updated: 2019/09/19 12:53:31 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lstnew;
	void	*cont;

	if (!(lstnew = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		lstnew->content = NULL;
		lstnew->content_size = 0;
	}
	else
	{
		if (!(cont = (void*)malloc(sizeof(*cont) * content_size)))
		{
			free(lstnew);
			return (NULL);
		}
		cont = ft_memcpy(cont, content, content_size);
		lstnew->content = cont;
		lstnew->content_size = content_size;
	}
	lstnew->next = NULL;
	return (lstnew);
}
