/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsizecpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 19:59:07 by lpousse           #+#    #+#             */
/*   Updated: 2016/09/19 20:02:43 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_wstrsizecpy(char *str, wchar_t *wstr, size_t size)
{
	size_t	i;

	i = 0;
	while (*wstr != '\0' && i + ft_wcharsize(*wstr) <= size)
	{
		ft_wcharcpy(str + i, *wstr);
		i += ft_wcharsize(*wstr);
		wstr++;
	}
}
