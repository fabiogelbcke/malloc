/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 20:06:42 by lpousse           #+#    #+#             */
/*   Updated: 2016/06/06 20:49:34 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar_fd(wchar_t c, int fd)
{
	if (c <= 0x7F)
		ft_putchar_fd(c, fd);
	else if (c <= 0x7FF)
	{
		ft_putchar_fd((c >> 6) + 0b11000000, fd);
		ft_putchar_fd((c & 0b111111) + 0b10000000, fd);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar_fd((c >> 12) + 0b11100000, fd);
		ft_putchar_fd(((c >> 6) & 0b111111) + 0b10000000, fd);
		ft_putchar_fd((c & 0b111111) + 0b10000000, fd);
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar_fd((c >> 18) + 0b11110000, fd);
		ft_putchar_fd(((c >> 12) & 0b111111) + 0b10000000, fd);
		ft_putchar_fd(((c >> 6) & 0b111111) + 0b10000000, fd);
		ft_putchar_fd((c & 0b111111) + 0b10000000, fd);
	}
}
