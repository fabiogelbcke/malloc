/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 17:03:31 by lpousse           #+#    #+#             */
/*   Updated: 2016/09/21 17:12:07 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(const wchar_t *src)
{
	wchar_t	*dest;

	dest = (wchar_t *)ft_strnew(ft_wstrsize(src));
	if (!dest)
		return (NULL);
	ft_wstrcpy(dest, src);
	return (dest);
}
