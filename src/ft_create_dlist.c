/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_dlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:53:21 by cghael            #+#    #+#             */
/*   Updated: 2019/11/08 13:53:43 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Contains addition function to create the decision list.
*/

#include "fillit_head.h"

/*
** \brief			Creates root node and first row in decision list.
** \param	n		The side of the square.
** \return	root	Head of the decision list.
*/

static t_dest	*ft_create_root(int n)
{
	t_dest	*root;

	root = ft_create_tdest('!', 0, 0);
	root->line = 0;
	if (!(root = ft_create_column_list(n, root)))
		return (NULL);
	return (root);
}

/*
** \brief			Function checks work of tetramino to map and if there
** 					smth goes wrong, clear memory.
** \param	root	Head of the decision list.
** 			tetmap	Node with new coords of tetrimino in map.
**			n		The side of the square.
** \return	root	Head of the decision list.
*/

static t_dest	*ft_add_decision_to_root(t_dest *root, t_tet *tetmap)
{
	if (ft_tetramino_to_map(root, tetmap) == NULL)
	{
		free(tetmap);
		ft_delete_dest_list(&root);
		return (NULL);
	}
	free(tetmap);
	return (root);
}

/*
** \brief			Function moves tetrimino in square.
** \param	tmp		Node with tetrimino.
** 			i		Offset by X.
**			j		Offset by Y.
** \return	root	Node with new coords.
*/

static t_tet	*ft_create_tetmap(t_tet *tmp, int i, int j)
{
	int		k;
	t_tet	*tetmap;

	if (!(tetmap = (t_tet*)malloc(sizeof(t_tet))))
		return (NULL);
	k = 0;
	tetmap->name = tmp->name;
	while (k < 4)
	{
		tetmap->x[k] = tmp->x[k] + j;
		tetmap->y[k] = tmp->y[k] + i;
		k++;
	}
	return (tetmap);
}

/*
** \brief			Function checks does the tetrimino with offset is in sqr.
** \param	tmp		Node with tetrimino.
** 			i		Offset by X.
**			j		Offset by Y.
**			n		Side of the sqr.
** \return	1		If it does.
**			0		If doesn't.
*/

static int		ft_checkpos(t_tet *tmp, int i, int j, int n)
{
	if ((tmp->x[0] + j < n) && (tmp->x[1] + j < n) && \
		(tmp->x[2] + j < n) && (tmp->x[3] + j < n) && \
		(tmp->y[0] + i < n) && (tmp->y[1] + i < n) && \
		(tmp->y[2] + i < n) && (tmp->y[3] + i < n))
		return (1);
	return (0);
}

/*
** \brief			Function creates decision list.
** \param	tetr	List with tetrimino.
**			n		The side of the square.
** \return	root	Head node of the decision list.
**			NULL	If smth wrong with malloc.
*/

t_dest			*ft_create_dlist(t_tet *tetr, int n)
{
	int		i;
	t_tet	*tetmap;
	t_dest	*root;
	int		square;

	square = n * n;
	if (!(root = ft_create_root(n)))
		return (NULL);
	while (tetr != NULL)
	{
		i = 0;
		while (i < square)
		{
			if (ft_checkpos(tetr, i / n, i % n, n))
			{
				if (!(tetmap = ft_create_tetmap(tetr, i / n, i % n)))
					return (NULL);
				if (!(root = ft_add_decision_to_root(root, tetmap)))
					return (NULL);
			}
			i++;
		}
		tetr = tetr->next;
	}
	return (root);
}