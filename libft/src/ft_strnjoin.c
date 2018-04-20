/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:15:11 by lpousse           #+#    #+#             */
/*   Updated: 2016/01/14 18:24:11 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*str;
	int		len;

	len = (ft_strlen(s2) > n ? n : ft_strlen(s2));
	if ((str = ft_strnew(ft_strlen(s1) + len)) != NULL)
	{
		ft_strcpy(str, s1);
		ft_strncat(str, s2, n);
		return (str);
	}
	return (NULL);
}
