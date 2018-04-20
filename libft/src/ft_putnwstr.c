/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:09:41 by lpousse           #+#    #+#             */
/*   Updated: 2016/02/08 15:12:02 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnwstr(wchar_t *wstr, size_t n)
{
	size_t	i;

	i = 0;
	while (wstr[i] != '\0' && i < n)
	{
		ft_putwchar(wstr[i]);
		i++;
	}
}
