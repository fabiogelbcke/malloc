/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_base_caps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:13:12 by lpousse           #+#    #+#             */
/*   Updated: 2016/02/10 18:31:16 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puts_base_caps(intmax_t n, int base)
{
	if (n < 0)
		ft_putchar('-');
	if (n > 0)
		n = -n;
	if (n <= -base)
	{
		ft_puts_base_caps(-(n / base), base);
		ft_puts_base_caps((base - (n % base)) % base, base);
	}
	else
	{
		if (n <= -10)
			ft_putchar(-n - 10 + 'A');
		else
			ft_putchar(-n + '0');
	}
}
