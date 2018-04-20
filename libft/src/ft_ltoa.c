/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:10:28 by lpousse           #+#    #+#             */
/*   Updated: 2016/01/25 18:49:22 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nblen(long n)
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

char		*ft_ltoa(long n)
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
