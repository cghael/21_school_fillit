/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_smallest_sqr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:07:22 by cghael            #+#    #+#             */
/*   Updated: 2019/11/08 14:23:40 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_head.h"

/*
** \brief				Main recursive algorithm, finds decision in
** 						Khnut'sdecision list.
** \param	root		Decision list.
** 			goal		Row, that we choose as a decision for tetrimino
** 			stack		List, where we save all cowered rows.
** 			tet_count	The number os tetrimino.
** \return	-1			If there is trouble with mallocs.
** 			0			If there is no decision this square.
** 			1			If we find the decision.
*/

static int	ft_fillit(t_dest *root, t_dest *goal, t_cwr **stack, int tet_count)
{
	t_list		*q;
	int			cov_res;
	char		a;

	if (goal->name == '!')
		return (1);
	a = goal->name;
	while (goal->name == a)
	{
		q = NULL;
		if ((cov_res = ft_cover_all(&q, goal)) < 0)
			return (-1);
		if (cov_res > 0)
		{
			ft_add_to_stack(stack, q);
			if (ft_fillit(root, goal->down, stack, tet_count) == 1)
				return (1);
			if (cov_res < 2)
				ft_uncover_and_free(stack, 1);
		}
		goal = goal->down;
	}
	return (0);
}

/*
** \brief			Function finds side of the sqr when fillit returns 1.
** \param	root	The decision list.
** 			tetr	Kist with income tetrimino.
** \return	-1		If we have some troubles with mallocs.
** 			1		When we find the decision.
*/

int			ft_find_smallest_sqr(t_tet *tetr, int n, t_dest **root)
{
	int			res;
	t_cwr		*stack;
	int			n_tet;

	res = 0;
	while (!res)
	{
		if (!(*root = ft_create_dlist(tetr, n)))
			return (-1);
		if ((*root)->down->name == 'A')
		{
			stack = NULL;
			n_tet = (*root)->up->name - 'A' + 1;
			if ((res = ft_fillit(*root, (*root)->down, &stack, n_tet)) != 0)
				break ;
			ft_uncover_and_free(&stack, 2);
		}
		ft_delete_dest_list(root);
		n++;
	}
	if (res == 1)
		ft_print_tetris(*root, n);
	ft_uncover_and_free(&stack, 2);
	return (res);
}
