/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:14:44 by lpousse           #+#    #+#             */
/*   Updated: 2016/06/06 20:27:57 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putu_base(uintmax_t n, unsigned int base)
{
	if (n >= base)
	{
		ft_putu_base(n / (uintmax_t)base, base);
		ft_putu_base(n % (uintmax_t)base, base);
	}
	else
	{
		if (n >= 10)
			ft_putchar(n - 10 + 'a');
		else
			ft_putchar(n + '0');
	}
}
