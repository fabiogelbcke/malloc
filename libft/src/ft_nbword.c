/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbword.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 21:03:23 by lpousse           #+#    #+#             */
/*   Updated: 2016/03/08 21:10:39 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbword(char *str)
{
	int		nbw;

	nbw = 0;
	while (*str != '\0')
	{
		while (ft_isspace(*str) == 1 && *str != '\0')
			str++;
		if (*str != '\0')
		{
			nbw++;
			while (ft_isspace(*str) == 0 && *str != '\0')
				str++;
		}
	}
	return (nbw);
}
