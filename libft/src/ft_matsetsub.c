/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matsetsub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:59:20 by lpousse           #+#    #+#             */
/*   Updated: 2016/03/22 18:03:04 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matsetsub(t_matrix *subm, t_matrix *m, int y, int x)
{
	int		i;
	int		j;
	int		iadd;
	int		jadd;

	i = 0;
	iadd = 0;
	while (i < subm->y)
	{
		if (i == y)
			iadd = 1;
		j = 0;
		jadd = 0;
		while (j < subm->x)
		{
			if (j == x)
				jadd = 1;
			(subm->m)[i][j] = (m->m)[i + iadd][j + jadd];
			j++;
		}
		i++;
	}
}
