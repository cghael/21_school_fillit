/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:36:14 by cghael            #+#    #+#             */
/*   Updated: 2019/10/03 16:48:50 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new;
	size_t		len;
	size_t		i;
	size_t		n;
	size_t		m;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	i = 0;
	n = 0;
	m = 0;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	if (len > i)
	{
		while (s1[n] != '\0')
			new[i++] = s1[n++];
		while (s2[m] != '\0')
			new[i++] = s2[m++];
	}
	if (i == len)
		new[i] = '\0';
	return (new);
}
