/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsizewstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 20:57:27 by lpousse           #+#    #+#             */
/*   Updated: 2016/02/15 21:02:01 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putsizewstr(wchar_t *wstr, size_t size)
{
	size_t i;

	i = 0;
	while (*wstr != '\0' && i + ft_wcharsize(*wstr) <= size)
	{
		ft_putwchar(*wstr);
		i += ft_wcharsize(*wstr);
		wstr++;
	}
}
