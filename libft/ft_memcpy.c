/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:44:16 by cghael            #+#    #+#             */
/*   Updated: 2019/09/09 20:32:53 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	unsigned char	*destp;
	unsigned char	*srcp;
	size_t			i;

	i = 0;
	destp = dest;
	srcp = (unsigned char*)source;
	if (!dest && !source)
		return (NULL);
	while (n--)
	{
		destp[i] = srcp[i];
		i++;
	}
	return (destp);
}
