/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:33:10 by cghael            #+#    #+#             */
/*   Updated: 2019/09/17 17:14:12 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*str_d;

	str_d = (char*)malloc(sizeof(*str_d) * (ft_strlen(str) + 1));
	if (!str_d)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str_d[i] = str[i];
		i++;
	}
	str_d[i] = '\0';
	return (str_d);
}
