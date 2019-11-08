/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:02:54 by cghael            #+#    #+#             */
/*   Updated: 2019/09/17 17:06:03 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char *strtmp;

	strtmp = (char*)str;
	while (*strtmp)
	{
		if (*strtmp == c)
			return (strtmp);
		strtmp++;
	}
	if (*strtmp == c)
		return (strtmp);
	else
		return (NULL);
}
