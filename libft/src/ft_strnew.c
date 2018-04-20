/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:14:09 by lpousse           #+#    #+#             */
/*   Updated: 2015/11/26 15:33:33 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if ((str = (char *)malloc(sizeof(char) * (size + 1))) != NULL)
	{
		i = 0;
		while (i < size + 1)
		{
			str[i] = '\0';
			i++;
		}
		return (str);
	}
	return (NULL);
}
