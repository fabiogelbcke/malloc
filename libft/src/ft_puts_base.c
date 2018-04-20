/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:01:45 by lpousse           #+#    #+#             */
/*   Updated: 2016/02/04 19:28:15 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puts_base(intmax_t n, int base)
{
	if (n < 0)
		ft_putchar('-');
	if (n > 0)
		n = -n;
	if (n <= -base)
	{
		ft_puts_base(-(n / base), base);
		ft_puts_base((base - (n % base)) % base, base);
	}
	else
	{
		if (n <= -10)
			ft_putchar(-n - 10 + 'a');
		else
			ft_putchar(-n + '0');
	}
}
