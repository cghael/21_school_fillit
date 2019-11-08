/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetramino_to_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgriseld <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:45:29 by dgriseld          #+#    #+#             */
/*   Updated: 2019/11/08 13:50:42 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Contains function to create the decision list.
*/

#include "fillit_head.h"

/*
** \brief			Function creates the row for decision list from the
** 					tetrimino node.
** \param	tet		Node with tetrimino.
** \return	head	Head node of the decision row.
**			NULL	If smth wrong with malloc.
*/

static t_dest	*ft_tetraminotostr(t_tet *tet)
{
	t_dest	*node;
	t_dest	*tmp;
	t_dest	*head;
	int		i;

	i = 0;
	if (!(head = ft_create_tdest(tet->name, 0, 0)))
		return (NULL);
	node = head;
	while (i < 4)
	{
		if (!(tmp = ft_create_tdest(tet->name, tet->x[i], tet->y[i])))
		{
			ft_delete_dest_row(head);
			return (NULL);
		}
		node->right = tmp;
		tmp->right = head;
		head->left = tmp;
		tmp->left = node;
		node = node->right;
		tmp->line = 0;
		i++;
	}
	return (head);
}

/*
** \brief			Function bind nodes in decision list.
** \param	head2	Node in decision list.
** 			tmp2	Node to bind.
*/

static void		ft_bind_node(t_dest **head2, t_dest **tmp2)
{
	t_dest	*node;
	t_dest	*head;
	t_dest	*tmp;

	head = *head2;
	tmp = *tmp2;
	node = head->up;
	head->up = tmp;
	tmp->up = node;
	node->down = tmp;
	tmp->down = head;
	tmp->head = head;
}

/*
** \brief			Function creates the row for decision list from the
** 					tetrimino node.
** \param	tet		Node with tetrimino.
** \return	head	Head node of the decision row.
**			NULL	If smth wrong with malloc.
*/

t_dest			*ft_tetramino_to_map(t_dest *begin, t_tet *tetmap)
{
	t_dest	*tmp;
	t_dest	*head;
	int		i;

	if (!(tmp = ft_tetraminotostr(tetmap)))
		return (NULL);
	tmp->line = begin->up->line + 1;
	ft_bind_node(&begin, &tmp);
	tmp = tmp->right;
	i = 0;
	while (i++ < 4)
	{
		head = begin->right;
		while (head != begin)
		{
			if (head->x == tmp->x && head->y == tmp->y)
			{
				ft_bind_node(&head, &tmp);
				break ;
			}
			head = head->right;
		}
		tmp = tmp->right;
	}
	return (begin);
}
