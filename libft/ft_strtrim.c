/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:44:23 by cghael            #+#    #+#             */
/*   Updated: 2019/09/15 18:57:08 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	len = ft_strlen(s) - 1;
	if (i == len + 1)
		return (ft_strnew(0));
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	str = ft_strnew(len - i + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (i <= len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
