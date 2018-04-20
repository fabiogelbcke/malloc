/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:21:33 by lpousse           #+#    #+#             */
/*   Updated: 2015/12/01 14:27:05 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		word_count(char const *s, char c)
{
	int		i;
	int		nbw;
	int		new;

	i = 0;
	nbw = 0;
	new = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c && new == 1)
		{
			nbw++;
			new = 0;
		}
		else if (s[i] == c)
			new = 1;
		i++;
	}
	return (nbw);
}

static int		word_len(char const *s, char c)
{
	int		len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		nbw;
	char	**tab;

	nbw = word_count(s, c);
	if ((tab = (char **)malloc(sizeof(char *) * nbw + 1)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < nbw)
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		tab[i] = ft_strsub(s, j, word_len((const char *)(s + j), c));
		if (tab[i] == NULL)
			return (NULL);
		j += word_len((const char *)(s + j), c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
