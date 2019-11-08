/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:33:05 by cghael            #+#    #+#             */
/*   Updated: 2019/09/17 17:07:53 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int ch, size_t n)
{
	unsigned char	*destp;
	unsigned char	*srcp;
	size_t			i;

	ch = (unsigned char)ch;
	destp = dest;
	srcp = (unsigned char*)source;
	i = 0;
	while (n--)
	{
		destp[i] = srcp[i];
		if (srcp[i] == ch)
			return (destp + i + 1);
		i++;
	}
	return (NULL);
}
