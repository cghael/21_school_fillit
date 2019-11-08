/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uncover_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:35:35 by cghael            #+#    #+#             */
/*   Updated: 2019/11/08 16:37:39 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_head.h"

/*
** \brief			Free the first node in stack.
** \param	&stack	Takes the beginning of the stack.
*/

static void	ft_stack_del_node(t_cwr **stack)
{
	t_list	*head;
	t_list	*tmp;
	t_cwr	*node;

	head = (t_list*)(*stack)->head;
	if ((*stack)->right == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		node = *stack;
		*stack = (*stack)->right;
		free(node);
	}
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/*
** \brief			Just uncover last cover and delete last node from stack
** 					or free all stack.
** \param	&stack	Takes the beginning of the stack, which contains all
**					covered rows.
**			1		If we need to free only the last stack node.
** 			2		If we need to free all stack.
*/

void		ft_uncover_and_free(t_cwr **stack, int i)
{
	if (!*stack)
		return ;
	if (i == 1)
	{
		ft_uncover((*stack)->head);
		ft_stack_del_node(stack);
	}
	else
	{
		while (*stack)
		{
			ft_uncover((*stack)->head);
			ft_stack_del_node(stack);
		}
	}
}
