/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:56:23 by lpousse           #+#    #+#             */
/*   Updated: 2016/06/01 19:00:33 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtabdel(char ***tab, size_t size)
{
	size_t	i;

	if (tab != NULL && *tab != NULL)
	{
		i = 0;
		while (i < size)
		{
			if ((*tab)[i] != NULL)
				free((*tab)[i]);
			i++;
		}
		free(*tab);
		*tab = NULL;
	}
}
