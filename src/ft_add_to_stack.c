/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:31:57 by cghael            #+#    #+#             */
/*   Updated: 2019/11/05 13:23:55 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file contains functions which create stack.
*/

#include "fillit_head.h"

/*
** \brief		Creates a new node which points left and right to itself and
**				head points to a queue of covered nodes from destination list.
** \params	new	The queue of cowered nodes.
*/

static t_cwr	*ft_create_stack_elem(t_list *new)
{
	t_cwr		*tmp;

	tmp = (t_cwr*)malloc(sizeof(t_cwr));
	if (!new)
		return (NULL);
	tmp->right = NULL;
	tmp->head = new;
	return (tmp);
}

/*
** \brief			Creates a new stack node and add it in the end of stack.
** \params	new		The queue of cowered nodes.
**			stack	The head of the stack.
*/

t_cwr			*ft_add_to_stack(t_cwr **stack, t_list *new)
{
	t_cwr	*tmp;

	if (!stack || !new)
		return (NULL);
	tmp = ft_create_stack_elem(new);
	if (!tmp)
		return (NULL);
	if (!*stack)
		*stack = tmp;
	else
	{
		tmp->right = *stack;
		*stack = tmp;
	}
	return (*stack);
}
