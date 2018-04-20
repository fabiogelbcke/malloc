/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matmulti_scal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:22:45 by lpousse           #+#    #+#             */
/*   Updated: 2016/03/17 16:58:52 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	*ft_matmulti_scal(t_matrix *a, double b)
{
	t_matrix	*result;
	int			i;
	int			j;

	if (!(result = ft_matnew(a->x, a->y)))
		return (NULL);
	i = -1;
	while (++i < a->y)
	{
		j = -1;
		while (++j < a->x)
			(result->m)[i][j] = (a->m)[i][j] * b;
	}
	return (result);
}
