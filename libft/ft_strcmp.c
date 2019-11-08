/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:14:44 by cghael            #+#    #+#             */
/*   Updated: 2019/09/17 17:04:43 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s_tmp1;
	unsigned char	*s_tmp2;

	s_tmp1 = (unsigned char*)s1;
	s_tmp2 = (unsigned char*)s2;
	while (*s_tmp1 && *s_tmp2 && *s_tmp1 == *s_tmp2)
	{
		s_tmp1++;
		s_tmp2++;
	}
	return (*s_tmp1 - *s_tmp2);
}
