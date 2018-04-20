/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 12:01:27 by lpousse           #+#    #+#             */
/*   Updated: 2016/03/29 16:01:32 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	exponent(double n)
{
	if (n <= -10)
		exponent(n / 10);
	ft_putchar((10 - ((long)n % 10)) % 10 + '0');
}

void		ft_putdouble(double n)
{
	int		i;

	if (n < 0)
		ft_putchar('-');
	if (n > 0)
		n = -n;
	exponent(n);
	n -= (long)n;
	if (n < 0)
		n = -n;
	ft_putchar('.');
	i = 0;
	while (i++ < 6)
	{
		n *= 10;
		ft_putchar((long)n % 10 + '0');
	}
}
