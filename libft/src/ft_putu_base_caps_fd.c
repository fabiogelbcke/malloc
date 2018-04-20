/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu_base_caps_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 20:16:15 by lpousse           #+#    #+#             */
/*   Updated: 2016/06/06 20:29:23 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putu_base_caps_fd(uintmax_t n, unsigned int base, int fd)
{
	if (n >= base)
	{
		ft_putu_base_caps_fd(n / (uintmax_t)base, base, fd);
		ft_putu_base_caps_fd(n % (uintmax_t)base, base, fd);
	}
	else
	{
		if (n >= 10)
			ft_putchar_fd(n - 10 + 'A', fd);
		else
			ft_putchar_fd(n + '0', fd);
	}
}
