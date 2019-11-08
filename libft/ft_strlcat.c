/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:04:49 by cghael            #+#    #+#             */
/*   Updated: 2019/09/17 17:01:40 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	ldst;
	size_t	lsrc;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	i = 0;
	if (n < ldst)
		return (n + lsrc);
	while ((n - ldst) > 1 && src[i])
	{
		dst[ldst + i] = src[i];
		i++;
		n--;
	}
	dst[ldst + i] = '\0';
	return (lsrc + ldst);
}
