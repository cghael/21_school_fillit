/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:30:13 by cghael            #+#    #+#             */
/*   Updated: 2019/11/08 16:36:57 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_head.h"

/*
** \brief			Check arguments. It must be only one. USAGE defined in .h
** \param	argc	Get from main.
** \return	-1		If argc != 2.
** \return	0		If everything is OK.
*/

int			ft_check_argc(int argc)
{
	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (-1);
	}
	return (0);
}
