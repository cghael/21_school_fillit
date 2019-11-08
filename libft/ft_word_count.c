/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:40:48 by cghael            #+#    #+#             */
/*   Updated: 2019/09/19 17:48:32 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	w_count;

	if (!s)
		return (0);
	i = 0;
	w_count = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		w_count++;
		i++;
	}
	return (w_count);
}
