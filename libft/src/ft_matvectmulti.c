/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matvectmulti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:23:39 by lpousse           #+#    #+#             */
/*   Updated: 2016/03/18 14:44:50 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_matvectmulti(t_matrix *a, t_vector *b)
{
	t_vector	*result;
	int			i;
	int			j;

	if (a->x != b->n || !(result = ft_vectnew(a->y)))
		return (NULL);
	i = -1;
	while (++i < result->n)
	{
		(result->v)[i] = 0;
		j = -1;
		while (++j < a->x)
			(result->v)[i] += (a->m)[i][j] * (b->v)[j];
	}
	return (result);
}
