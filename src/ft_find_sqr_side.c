/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_sqr_side.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:21:24 by cghael            #+#    #+#             */
/*   Updated: 2019/11/08 14:23:40 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_head.h"

/*
** \brief			Finds the smallest side of the square depending on the
**					tetrimino quantity.
** \param	tetr	List with read tatriminos.
** \return			The side of the square.
*/

int			ft_find_sqr_side(t_tet *tetr)
{
	int n_tetr;
	int sqr_s;
	int tmp;

	n_tetr = 0;
	while (tetr)
	{
		n_tetr++;
		tetr = tetr->next;
	}
	sqr_s = n_tetr * 4;
	tmp = sqr_s / 2;
	while (tmp > 1)
	{
		if (sqr_s == tmp * tmp)
			return (tmp);
		if (sqr_s > tmp * tmp)
			return (tmp + 1);
		tmp = tmp - 1;
	}
	return (0);
}
