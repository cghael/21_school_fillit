/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:59:04 by cghael            #+#    #+#             */
/*   Updated: 2019/09/17 17:07:37 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*src;

	src = (unsigned char*)arr;
	c = (unsigned char)c;
	while (n)
	{
		if (*src == c)
			return (src);
		src++;
		n--;
	}
	return (NULL);
}
