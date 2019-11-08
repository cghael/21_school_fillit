/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:29:01 by cghael            #+#    #+#             */
/*   Updated: 2019/09/17 16:57:08 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s_tmp1;
	unsigned char	*s_tmp2;

	s_tmp1 = (unsigned char*)s1;
	s_tmp2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (*s_tmp1 && *s_tmp2 && n - 1 && *s_tmp1 == *s_tmp2)
	{
		s_tmp1++;
		s_tmp2++;
		n--;
	}
	return (*s_tmp1 - *s_tmp2);
}
