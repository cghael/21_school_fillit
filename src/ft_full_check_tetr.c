/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_check_tetr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <cghael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:03:16 by cghael            #+#    #+#             */
/*   Updated: 2019/11/08 13:29:41 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file contains all functions to check the incoming file for validity.
*/

#include "fillit_head.h"

/*
** \brief		Check that blocks make up tetrimino. In valid tetrimino each
** 				block must touch at least one other block on any side.
** \param	buf	Read from file.
** \return	-1	If tetrimino isn't valid.
** \return	0	If tetrimino is OK.
*/

static int	ft_check_tetrimino_blocks(char *buf)
{
	int	i;
	int	touch_count;

	i = 0;
	touch_count = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (buf[i + 1] == '#')
				touch_count++;
			if (i < 15 && buf[i + 5] == '#')
				touch_count++;
		}
		i++;
	}
	if (touch_count < 3)
		return (-1);
	return (0);
}

/*
** \brief		Check number of tetrimino blocks (the '#' number must be 4).
** \param	buf	Read from file.
** \return	-1	If tetrimino isn't valid.
** \return	0	If tetrimino is OK.
*/

static int	ft_chek_tetrimino_fill(char *buf)
{
	int i;
	int block_count;

	i = 0;
	block_count = 0;
	while (i < (BUFFSIZE - SEPARATE))
	{
		if (buf[i] == '#')
			block_count++;
		i++;
	}
	if (block_count != 4)
		return (-1);
	return (0);
}

/*
** \brief		Check tetrimino size (it must be 4x4 square) and a newline
** 				at the end of each tetrimino.
** \param	buf	Read from file.
** \return	-1	If tetrimino isn't valid.
** \return	0 	If everything is OK and it's a valid tetrimino.
*/

static int	ft_check_size_newline(int res, char *buf)
{
	int i;

	i = 0;
	if (res == BUFFSIZE)
		while (buf[i])
		{
			if (((i + 1) % 5 == 0 || i == 20) && i > 0 && buf[i] != '\n')
				return (-1);
			if (((i + 1) % 5 != 0 && i < 20) && \
				(buf[i] != '.' && buf[i] != '#'))
				return (-1);
			i++;
		}
	else
		while (buf[i])
		{
			if ((((i + 1) % 5 == 0) && i > 0) && buf[i] != '\n')
				return (-1);
			if (((i + 1) % 5 != 0) && (buf[i] != '.' && buf[i] != '#'))
				return (-1);
			i++;
		}
	return (0);
}

/*
** \brief		Contains all checks of tetrimino to validity.
** \param	buf	Has been read from file. BUFF_SIZE = 21, last read is diff.
** \return	-1	If tetrimino is not valid (free list).
** \return	0 	If everything is OK and it's a valid tetrimino.
*/

int			ft_full_check_tetr(int res, char *buf)
{
	if (res < (BUFFSIZE - SEPARATE - 1) || res > BUFFSIZE)
		return (-1);
	if (ft_check_size_newline(res, buf) < 0)
		return (-1);
	if (ft_chek_tetrimino_fill(buf) < 0)
		return (-1);
	if (ft_check_tetrimino_blocks(buf) < 0)
		return (-1);
	return (0);
}
