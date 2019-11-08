/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgriseld <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:30:14 by dgriseld          #+#    #+#             */
/*   Updated: 2019/11/06 14:34:21 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_head.h"

void	ft_print_tetris(t_dest *map, int n)
{
	int		i;
	int		f;
	t_dest	*head;
	t_dest	*headcol;

	head = map;
	i = 0;
	f = 0;
	while (head != map->right)
	{
		headcol = map->right;
		map = map->right->down;
		while (headcol != map)
		{
			write(1, &map->name, 1);
			map = map->down;
			f = 1;
		}
		(f != 1) ? write(1, ".", 1) : (f = 0);
		i++;
		(i == n) ? write(1, "\n", 1) : 1;
		i = ((i == n) ? 0 : i);
	}
}
