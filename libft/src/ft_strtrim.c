/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:31:21 by lpousse           #+#    #+#             */
/*   Updated: 2015/12/01 14:12:39 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		len;
	char	*str;

	start = 0;
	end = 0;
	len = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[len - end] == ' ' || s[len - end] == '\n' || s[len - end] == '\t')
		end++;
	if (len - start - end <= 0)
		return ("");
	if ((str = ft_strsub(s, start, (len + 1 - start - end))) != NULL)
		return (str);
	return (NULL);
}
