/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 20:19:24 by lpousse           #+#    #+#             */
/*   Updated: 2016/06/06 20:49:53 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnwstr_fd(wchar_t *wstr, size_t n, int fd)
{
	size_t	i;

	i = 0;
	while (wstr[i] != '\0' && i < n)
	{
		ft_putwchar_fd(wstr[i], fd);
		i++;
	}
}
