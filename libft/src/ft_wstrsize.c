/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:18:14 by lpousse           #+#    #+#             */
/*   Updated: 2016/09/21 17:18:46 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrsize(const wchar_t *wstr)
{
	size_t	size;

	size = 0;
	while (*wstr != '\0')
		size += ft_wcharsize(*wstr++);
	return (size);
}
