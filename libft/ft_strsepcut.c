/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsepcut.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:01:53 by cghael            #+#    #+#             */
/*   Updated: 2019/09/18 16:59:46 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy_mod(char *dst, const char *src, char c, size_t len)
{
	size_t	i;
	size_t	j;

	src = (char*)src;
	i = 0;
	j = 0;
	while (src[i] && j < len)
	{
		if (src[i] != c || (src[i] == c && src[i - 1] != c))
		{
			dst[j] = src[i];
			j++;
		}
		i++;
	}
	return (dst);
}

char		*ft_strsepcut(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (*s == c)
		s++;
	if ((len = ft_strlen(s)) == 0)
		return (ft_strnew(0));
	while (s[len - 1] == c)
		len--;
	j = 0;
	while (i < len)
	{
		if (s[i] != c || (s[i] == c && s[i - 1] != c))
			j++;
		i++;
	}
	if (!(str = ft_memalloc(j + 1)))
		return (NULL);
	str = ft_strcpy_mod(str, s, c, j);
	return (str);
}
