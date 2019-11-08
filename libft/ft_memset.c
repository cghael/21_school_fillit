/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:49:14 by cghael            #+#    #+#             */
/*   Updated: 2019/09/17 17:06:49 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*dest_n;
	size_t			i;

	i = 0;
	dest_n = dest;
	c = (unsigned char)c;
	while (n--)
	{
		dest_n[i] = c;
		i++;
	}
	return (dest);
}
