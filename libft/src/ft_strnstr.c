/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:37:16 by lpousse           #+#    #+#             */
/*   Updated: 2015/11/30 16:15:11 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	if (ft_strlen((char *)s2) <= 0)
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0' && i < (int)n)
	{
		j = 0;
		while (s2[j] != '\0' && s1[i + j] != '\0' && s2[j] == s1[i + j]
				&& i + j < (int)n)
		{
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
