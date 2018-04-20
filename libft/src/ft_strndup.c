/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:30:36 by lpousse           #+#    #+#             */
/*   Updated: 2016/11/14 15:16:47 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(src);
	dest = ft_strnew(len > n ? n : len);
	if (!dest)
		return (NULL);
	ft_strncpy(dest, src, n);
	return (dest);
}
