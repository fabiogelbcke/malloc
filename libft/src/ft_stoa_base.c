/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:48:42 by lpousse           #+#    #+#             */
/*   Updated: 2016/01/29 16:42:01 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nblen(intmax_t n, int base)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= base;
	}
	return (i);
}

char		*ft_stoa_base(intmax_t n, int base)
{
	int		i;
	int		neg;
	int		tmp;
	char	*str;

	neg = 1;
	if (n >= 0)
	{
		n = -n;
		neg = 0;
	}
	i = nblen(n, base);
	if ((str = ft_strnew(i + neg)) == NULL)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	while (i-- > 0)
	{
		if ((tmp = (base - (n % base)) % base) > 9)
			str[i + neg] = tmp - 10 + 'a';
		else
			str[i + neg] = tmp + '0';
		n /= base;
	}
	return (str);
}
