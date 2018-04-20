/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:36:39 by lpousse           #+#    #+#             */
/*   Updated: 2016/01/25 18:44:59 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nblen(unsigned short n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_hutoa(unsigned short n)
{
	int		i;
	char	*str;

	i = nblen(n);
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	while (i > 0)
	{
		i--;
		str[i] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}
