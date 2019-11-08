/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:07:04 by cghael            #+#    #+#             */
/*   Updated: 2019/09/19 17:48:29 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memfree(char *str, char **strsl, size_t i)
{
	size_t	j;

	j = 0;
	free(str);
	while (j < i)
	{
		free(strsl[j]);
		j++;
	}
	free(strsl);
	return (NULL);
}

static char	*ft_strcreate(char *str, size_t s_end, size_t s_begin)
{
	size_t	len;
	char	*n_str;

	len = s_end - s_begin;
	if (!(n_str = (char*)malloc(sizeof(*n_str) * (len + 1))))
		return (NULL);
	n_str = ft_strncpy(n_str, str + s_begin, len);
	n_str[len] = '\0';
	return (n_str);
}

static char	**ft_words(char **strsl, char *str, size_t n_words, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < n_words && n_words != 0)
	{
		if (str[j] == c || str[j] == '\0')
		{
			if (!(strsl[i] = ft_strcreate(str, j, k)))
				return (ft_memfree(str, strsl, i));
			i++;
			k = j + 1;
		}
		j++;
	}
	strsl[i] = NULL;
	return (strsl);
}

char		**ft_strsplit(char const *s, char c)
{
	char	*str;
	char	**strsl;
	size_t	n_words;

	if (!s)
		return (NULL);
	if ((str = ft_strsepcut(s, c)) == NULL)
		return (NULL);
	n_words = ft_word_count(str, c);
	if (!(strsl = (char**)malloc(sizeof(char*) * (n_words + 1))))
	{
		free(str);
		return (NULL);
	}
	return (ft_words(strsl, str, n_words, c));
}
