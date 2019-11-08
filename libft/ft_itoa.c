/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:54:43 by cghael            #+#    #+#             */
/*   Updated: 2019/09/17 16:18:12 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_memsize(int n)
{
	size_t	size;

	size = 1;
	if (n < 0)
		size++;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*ft_fillnum(char *str, int n, size_t size)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		str[size - 2] = '0' + (nb % 10);
		nb = nb / 10;
		size--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	if (n == 0)
	{
		str = ft_memalloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		return (str);
	}
	size = ft_memsize(n);
	str = ft_memalloc(size);
	if (!str)
		return (NULL);
	str = ft_fillnum(str, n, size);
	return (str);
}
