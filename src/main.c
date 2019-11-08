/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgriseld <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:48:25 by dgriseld          #+#    #+#             */
/*   Updated: 2019/11/06 14:04:59 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_head.h"

int				main(int argc, char **argv)
{
	int			fd;
	t_tet		*tetr;
	t_dest		*root;
	int			n;

	if (ft_check_argc(argc) < 0)
		return (-1);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		write(2, "error\n", 6);
		return (-1);
	}
	if (!(tetr = ft_read_tetrimino(fd)))
		return (-1);
	n = ft_find_sqr_side(tetr);
	if (ft_find_smallest_sqr(tetr, n, &root) < 0)
	{
		ft_delete_tet_list(tetr);
		ft_delete_dest_list(&root);
		write(2, "error\n", 6);
		return (-1);
	}
	ft_delete_dest_list(&root);
	ft_delete_tet_list(tetr);
	return (0);
}
