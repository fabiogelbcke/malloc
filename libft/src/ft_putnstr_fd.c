/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 20:24:20 by lpousse           #+#    #+#             */
/*   Updated: 2016/06/06 20:50:32 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(char *str, size_t n, int fd)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && i < n)
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}