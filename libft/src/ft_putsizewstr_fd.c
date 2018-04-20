/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsizewstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 20:20:24 by lpousse           #+#    #+#             */
/*   Updated: 2016/06/06 20:21:45 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putsizewstr_fd(wchar_t *wstr, size_t size, int fd)
{
	size_t i;

	i = 0;
	while (*wstr != '\0' && i + ft_wcharsize(*wstr) <= size)
	{
		ft_putwchar_fd(*wstr, fd);
		i += ft_wcharsize(*wstr);
		wstr++;
	}
}
