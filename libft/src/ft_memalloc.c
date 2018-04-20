/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:57:36 by lpousse           #+#    #+#             */
/*   Updated: 2015/11/30 15:12:10 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	char	*memzone;
	size_t	i;

	i = 0;
	if ((memzone = (char *)malloc(size)) != NULL)
	{
		while (i < size)
		{
			memzone[i] = 0;
			i++;
		}
		return ((void *)memzone);
	}
	return (NULL);
}
