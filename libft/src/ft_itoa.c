/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:52:27 by lpousse           #+#    #+#             */
/*   Updated: 2015/11/26 18:13:51 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nblen(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		neg;
	char	*str;

	neg = 1;
	if (n >= 0)
	{
		n = -n;
		neg = 0;
	}
	i = nblen(n);
	if ((str = ft_strnew(i + neg)) == NULL)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	while (i > 0)
	{
		i--;
		str[i + neg] = (10 - (n % 10)) % 10 + 48;
		n /= 10;
	}
	return (str);
}
