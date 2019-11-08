/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:37:59 by cghael            #+#    #+#             */
/*   Updated: 2019/09/13 18:31:35 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str_b, const char *str_a, size_t n)
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
	while (*b && n)
	{
		i = 0;
		while (a[i] == b[i] && i < n)
		{
			if (a[i + 1] == '\0')
				return (b);
			i++;
		}
		n--;
		b++;
	}
	return (NULL);
}
