/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:17:01 by cghael            #+#    #+#             */
/*   Updated: 2019/09/15 13:33:54 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*mem;

	mem = (char*)malloc(sizeof(*mem) * size);
	if (!mem)
		return (0);
	i = 0;
	while (i < size)
		mem[i++] = '\0';
	return (mem);
}
