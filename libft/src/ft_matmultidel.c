/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matmultidel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:13:59 by lpousse           #+#    #+#             */
/*   Updated: 2016/04/05 15:16:50 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	*ft_matmultidel(t_matrix *a, t_matrix *b)
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
	ft_matdel(&a);
	ft_matdel(&b);
	return (result);
}
