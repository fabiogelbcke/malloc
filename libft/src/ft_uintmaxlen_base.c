/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmaxlen_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 15:25:45 by lpousse           #+#    #+#             */
/*   Updated: 2016/02/04 17:28:20 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uintmaxlen_base(uintmax_t n, unsigned int base)
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
