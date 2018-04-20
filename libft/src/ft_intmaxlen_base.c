/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxlen_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 15:17:41 by lpousse           #+#    #+#             */
/*   Updated: 2016/02/04 15:30:08 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intmaxlen_base(intmax_t n, int base)
{
	size_t len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}
