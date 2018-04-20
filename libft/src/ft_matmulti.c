/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matmulti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:31:10 by lpousse           #+#    #+#             */
/*   Updated: 2016/03/17 16:57:39 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	*ft_matmulti(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;
	int			i;
	int			j;
	int			k;

	if (a->x != b->y || !(result = ft_matnew(b->x, a->y)))
		return (NULL);
	i = -1;
	while (++i < result->y)
	{
		j = -1;
		while (++j < result->x)
		{
			(result->m)[i][j] = 0;
			k = -1;
			while (++k < a->x)
				(result->m)[i][j] += (a->m)[i][k] * (b->m)[k][j];
		}
	}
	return (result);
}
