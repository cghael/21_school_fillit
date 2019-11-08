/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:17:19 by cghael            #+#    #+#             */
/*   Updated: 2019/09/12 19:20:01 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*strtmp;

	strtmp = (char*)s + ft_strlen(s);
	while (strtmp != s)
	{
		if (*strtmp == c)
			return (strtmp);
		strtmp--;
	}
	if (*strtmp == c)
		return (strtmp);
	else
		return (NULL);
}
