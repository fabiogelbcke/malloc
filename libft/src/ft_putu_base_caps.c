/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu_base_caps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:23:22 by lpousse           #+#    #+#             */
/*   Updated: 2016/02/10 18:30:59 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putu_base_caps(uintmax_t n, unsigned int base)
{
	if (n >= base)
	{
		ft_putu_base_caps(n / (uintmax_t)base, base);
		ft_putu_base_caps(n % (uintmax_t)base, base);
	}
	else
	{
		if (n >= 10)
			ft_putchar(n - 10 + 'A');
		else
			ft_putchar(n + '0');
	}
}
