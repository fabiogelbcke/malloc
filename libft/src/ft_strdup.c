/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:11:43 by lpousse           #+#    #+#             */
/*   Updated: 2016/05/31 16:57:39 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = ft_strnew(ft_strlen(src));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}
