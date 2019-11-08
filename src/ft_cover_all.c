/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cover_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgriseld <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:23:34 by dgriseld          #+#    #+#             */
/*   Updated: 2019/11/08 14:01:15 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** In this file we are dancing with links. Cover, uncover and other shit.
*/

#include "fillit_head.h"

/*
** \brief			Function covers target row from the decision list.
** \param	rowcvr	Target row.
**			queue	List that contains all covered rows.
** \return	0		If target row is the last decision for some tetrimino.
**			-1		If there is some troubles with malloc.
**			1		If everything OK.
*/

static int		ft_cover_row(t_dest *rowcvr, t_list **queue)
{
	t_dest	*row;
	t_list	*tmp;

	if (rowcvr->name != rowcvr->up->name && rowcvr->name != rowcvr->down->name)
		return (0);
	row = rowcvr;
	tmp = (t_list*)malloc(sizeof(t_list));
	if (!tmp)
		return (-1);
	tmp->content = row;
	tmp->next = NULL;
	ft_lstadd(queue, tmp);
	while (row != rowcvr->left)
	{
		(row->up)->down = row->down;
		(row->down)->up = row->up;
		row = row->right;
	}
	(row->up)->down = row->down;
	(row->down)->up = row->up;
	return (1);
}

/*
** \brief			Function covers all rows, that contains nodes with the
** 					same coors as a goal.
** \param	goal	Row, which we choose as decision.
**			queue	List that contains all covered rows.
** \return	0		If row that we want to cower is the last decision for some
** 					tetrimino.
**			-1		If there is some troubles with malloc if ft_cover_row.
**			1		If everything OK.
*/

static int		ft_cover_cross_row(t_list **queue, t_dest *goal)
{
	t_dest	*tmp;
	t_dest	*t_down;
	t_dest	*t_left;
	int		res;

	tmp = goal->right;
	while (tmp != goal)
	{
		t_down = tmp->down;
		if (t_down->name == '@')
			t_down = t_down->down;
		while (t_down != tmp)
		{
			t_left = t_down->left;
			while (t_left->line == 0)
				t_left = t_left->left;
			if ((res = ft_cover_row(t_left, queue)) < 1)
				return (res);
			if (t_down->down->name == '@')
				t_down = t_down->down;
			t_down = t_down->down;
		}
		tmp = tmp->right;
	}
	return (1);
}

/*
** \brief			Function covers all rows that are decisions of the same
** 					tetrimino, as in goal.
** \param	goal	Row, which we choose as decision.
**			queue	List that contains all covered rows.
*/

static void		ft_cover_same_name(t_dest *goal, t_list **queue)
{
	t_dest	*node;

	node = goal->down;
	while (node != goal)
	{
		if (goal->name == node->name)
			ft_cover_row(node, queue);
		node = node->down;
	}
}

/*
** \brief			Function covers all rows that do not suit us. If there is
** 					some troubles or we are trying to cover last decision, it
** 					won't let as do it.
** \param	goal	Row, which we choose as decision.
**			queue	List that contains all covered rows.
** \return	0		If row that we want to cower is the last decision for some
** 					tetrimino.
**			-1		If there is some troubles with malloc if ft_cover_row.
**			1		If we cover smth.
**			2		If we didn't find the row to cover.
*/

int				ft_cover_all(t_list **queue, t_dest *goal)
{
	int		res;
	t_list	*tmp;

	ft_cover_same_name(goal, queue);
	res = ft_cover_cross_row(queue, goal);
	if (res < 1)
	{
		ft_uncover(*queue);
		while (*queue)
		{
			tmp = (*queue)->next;
			free(*queue);
			*queue = tmp;
		}
		return (res);
	}
	if (!*queue)
		return (2);
	return (1);
}
