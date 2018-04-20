/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:28:12 by lpousse           #+#    #+#             */
/*   Updated: 2016/09/21 16:35:27 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nblen(uintmax_t n, int base)
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

char		*ft_utoa_base(uintmax_t n, int base)
{
	int		i;
	char	*str;

	i = nblen(n, base);
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	while (i > 0)
	{
		i--;
		if (n % base >= 10)
			str[i] = n % base - 10 + 'a';
		else
			str[i] = n % base + '0';
		n /= base;
	}
	return (str);
}
