/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:12:01 by cghael            #+#    #+#             */
/*   Updated: 2019/09/13 18:36:24 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MAX_LINT 9223372036854775807

static char		*ft_skip(const char *str)
{
	char *tmp;

	tmp = (char*)str;
	while (*tmp == '\t' || *tmp == '\r' || *tmp == ' ' || *tmp == '\n' \
			|| *tmp == '\v' || *tmp == '\f')
		tmp++;
	return (tmp);
}

int				ft_atoi(const char *str)
{
	char					*tmp;
	int						minus;
	unsigned long long int	res;

	tmp = ft_skip(str);
	minus = (*tmp == '-') ? -1 : 1;
	tmp += (*tmp == '-' || *tmp == '+') ? 1 : 0;
	if (*tmp < 48 && *tmp > 57)
		return (0);
	res = 0;
	while (*tmp >= 48 && *tmp <= 57)
	{
		res = res * 10 + (*tmp - '0');
		tmp++;
	}
	if (res > MAX_LINT && minus < 0)
		return (0);
	if (res > MAX_LINT && minus > 0)
		return (-1);
	res = (minus < 0) ? res * minus : res;
	return ((int)res);
}
