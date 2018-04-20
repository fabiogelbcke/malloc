/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 15:00:17 by lpousse           #+#    #+#             */
/*   Updated: 2016/04/04 13:23:13 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *str)
{
	double	d;
	int		neg;
	int		decimal;

	d = 0;
	neg = 0;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
		neg = (*str++ == '-');
	while (*str >= '0' && *str <= '9')
		d = d * 10 + *str++ - 48;
	if (*str++ == '.')
	{
		decimal = 0;
		while (*str >= '0' && *str <= '9')
		{
			d = d * 10 + *str++ - 48;
			decimal++;
		}
		while (decimal-- > 0)
			d /= 10;
	}
	return (neg ? -d : d);
}
