/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:29:40 by cghael            #+#    #+#             */
/*   Updated: 2019/09/17 17:04:30 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *destptr, const char *srcptr)
{
	size_t	i;

	i = 0;
	while (srcptr[i])
	{
		destptr[i] = srcptr[i];
		i++;
	}
	destptr[i] = '\0';
	return (destptr);
}
