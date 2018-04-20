/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 19:52:57 by lpousse           #+#    #+#             */
/*   Updated: 2016/09/19 19:56:47 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_wcharcpy(char *str, wchar_t c)
{
	if (c <= 0x7F)
		str[0] = c;
	else if (c <= 0x7FF)
	{
		str[0] = (c >> 6) + 0b11000000;
		str[1] = (c & 0b111111) + 0b10000000;
	}
	else if (c <= 0xFFFF)
	{
		str[0] = (c >> 12) + 0b11100000;
		str[1] = ((c >> 6) & 0b111111) + 0b10000000;
		str[2] = (c & 0b111111) + 0b10000000;
	}
	else if (c <= 0x10FFFF)
	{
		str[0] = (c >> 18) + 0b11110000;
		str[1] = ((c >> 12) & 0b111111) + 0b10000000;
		str[2] = ((c >> 6) & 0b111111) + 0b10000000;
		str[3] = (c & 0b111111) + 0b10000000;
	}
}