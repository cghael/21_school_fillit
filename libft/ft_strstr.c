/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:27:22 by cghael            #+#    #+#             */
/*   Updated: 2019/09/12 20:00:53 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str_b, const char *str_a)
{
	size_t	len;
	size_t	i;
	char	*a;
	char	*b;

	a = (char*)str_a;
	b = (char*)str_b;
	len = ft_strlen(a);
	if (len == 0)
		return (b);
	while (*b)
	{
		if (*b == *a)
		{
			i = 0;
			while (a[i] == b[i] && a[i])
				i++;
			if (i == len)
				return (b);
		}
		b++;
	}
	return (NULL);
}
