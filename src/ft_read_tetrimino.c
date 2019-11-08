/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tetrimino.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <cghael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:18:36 by cghael            #+#    #+#             */
/*   Updated: 2019/11/07 17:21:35 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file contains all function to read tetrimino from the file.
*/

#include "fillit_head.h"

/*
** \brief				This func just prinf error massage and free tet list.
** \param	begin_list	The beginning of the tet list.
** \return	NULL
*/

static t_tet	*ft_error_tet_list(t_tet *begin_list)
{
	write(1, "error\n", 6);
	ft_delete_tet_list(begin_list);
	return (NULL);
}

/*
** \brief			Add new tet node at the end of the tet list.
** \param	tetr	The beginning of the tet list.
** 			new		The new tet node.
*/

static void		ft_lstadd_back(t_tet **tetr, t_tet *new)
{
	t_tet	*tmp;

	if (!tetr || !new)
		return ;
	tmp = *tetr;
	if (!tmp)
		*tetr = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

/*
** \brief			Fix coords of the tetr blocks so that the tetr will be at
** 					the upper left position.
** \param	tmp		The tetr node.
** 			j		Number of the tetr block.
*/

static void		ft_fix_coords(t_tet *tmp, int j)
{
	int x_min;
	int y_min;

	x_min = tmp->x[0];
	y_min = tmp->y[0];
	while (j >= 0)
	{
		if (tmp->x[j] < x_min)
			x_min = tmp->x[j];
		if (tmp->y[j] < y_min)
			y_min = tmp->y[j];
		j--;
	}
	j = 0;
	while (j < 4)
	{
		tmp->x[j] = tmp->x[j] - x_min;
		tmp->y[j] = tmp->y[j] - y_min;
		j++;
	}
}

/*
** \brief			Save read tetrimino to the tetr list.
** \param	str		Buff read from the file.
** 			tetr	The beginning of the list with tetriminos
**			f		Number of reads.
*/

static int		ft_get_tetrimino(const char *str, t_tet **tetr, int f)
{
	int			i;
	int			j;
	t_tet		*t;

	if (f >= 26)
		return (-1);
	i = 0;
	j = 0;
	if (!(t = (t_tet*)malloc(sizeof(t_tet))))
		return (-1);
	while (str[i] != '\0' && j < 4)
	{
		if (str[i] == '#')
		{
			t->x[j] = i % 5;
			t->y[j] = i / 5;
			j++;
		}
		i++;
	}
	ft_fix_coords(t, j - 1);
	t->name = 'A' + f;
	t->next = NULL;
	ft_lstadd_back(tetr, t);
	return (0);
}

/*
** \brief			Read tetrimino from the file and save to the tetr list.
** \param	fd		File descriptor of the open file.
** \return	NULL	If smth goes wrong with mallocs.
**			tetr	The begining of the tetr list.
*/

t_tet			*ft_read_tetrimino(int fd)
{
	char		buf[BUFFSIZE + 1];
	size_t		i;
	t_tet		*tetr;
	int			res;
	int			prev_res;

	tetr = NULL;
	if (read(fd, buf, 0) < 0)
		return (NULL);
	i = 0;
	prev_res = BUFFSIZE;
	while ((res = read(fd, buf, BUFFSIZE)) > 0)
	{
		buf[res] = '\0';
		if (ft_full_check_tetr(res, buf) < 0)
			return (ft_error_tet_list(tetr));
		if (ft_get_tetrimino(buf, &tetr, i) < 0)
			return (ft_error_tet_list(tetr));
		i++;
		prev_res = res;
	}
	if (res == 0 && prev_res != BUFFSIZE - SEPARATE)
		return (ft_error_tet_list(tetr));
	return (tetr);
}
