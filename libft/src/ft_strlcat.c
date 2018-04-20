/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:04:05 by lpousse           #+#    #+#             */
/*   Updated: 2015/12/01 16:22:22 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	i;
	size_t	j;

	dstlen = 0;
	while (dst[dstlen] != '\0' && dstlen < size)
		dstlen++;
	i = dstlen;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (dstlen < size)
		dst[i] = '\0';
	return (dstlen + ft_strlen(src));
}
