/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:45:58 by cghael            #+#    #+#             */
/*   Updated: 2019/09/17 16:56:32 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destptr, const char *srcptr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && srcptr[i])
	{
		destptr[i] = srcptr[i];
		i++;
	}
	while (i < n)
	{
		destptr[i] = '\0';
		i++;
	}
	return (destptr);
}
