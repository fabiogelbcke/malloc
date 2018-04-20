/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:16:58 by lpousse           #+#    #+#             */
/*   Updated: 2016/06/01 18:56:51 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabadd(char ***tab, size_t tablen, char *str)
{
	char	**newtab;
	size_t	i;

	newtab = (char **)malloc(sizeof(char *) * (tablen + 1));
	if (!newtab)
		return (NULL);
	newtab[tablen] = str;
	i = 0;
	while (i < tablen)
	{
		newtab[i] = (*tab)[i];
		i++;
	}
	free(*tab);
	*tab = NULL;
	return (newtab);
}
