/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:56:06 by lpousse           #+#    #+#             */
/*   Updated: 2016/02/04 19:29:51 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int n, int base)
{
	if (n < 0)
		ft_putchar('-');
	if (n > 0)
		n = -n;
	if (n <= -base)
	{
		ft_putnbr_base(-(n / base), base);
		ft_putnbr_base((base - (n % base)) % base, base);
	}
	else
	{
		if (n <= -10)
			ft_putchar(-n - 10 + 'a');
		else
			ft_putchar(-n + '0');
	}
}
