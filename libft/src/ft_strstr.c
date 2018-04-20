/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:50:27 by lpousse           #+#    #+#             */
/*   Updated: 2015/11/28 12:53:06 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	if (ft_strlen(s2) <= 0)
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0' && s1[i + j] != '\0' && s2[j] == s1[i + j])
		{
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
