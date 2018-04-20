/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintmaxns_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 20:10:43 by lpousse           #+#    #+#             */
/*   Updated: 2016/06/06 20:14:44 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putintmaxns_fd(intmax_t n, int fd)
{
	if (n > 0)
		n = -n;
	if (n <= -10)
	{
		ft_putintmaxns_fd(n / 10, fd);
		ft_putintmaxns_fd((10 - (n % 10)) % 10, fd);
	}
	else
		ft_putchar_fd(-n + '0', fd);
}
