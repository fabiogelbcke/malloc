/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:36:25 by lpousse           #+#    #+#             */
/*   Updated: 2016/04/05 13:15:18 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	*ft_matnew(int y, int x)
{
	t_matrix *matrix;

	if (y == 0 || x == 0)
		return (NULL);
	if ((matrix = (t_matrix *)malloc(sizeof(t_matrix))) == NULL)
		return (NULL);
	matrix->x = x;
	matrix->y = y;
	if (!(matrix->m = (double **)malloc(sizeof(double *) * y)))
		return (NULL);
	while (y > 0)
	{
		y--;
		if (!((matrix->m)[y] = (double *)malloc(sizeof(double) * x)))
			return (NULL);
	}
	ft_matclr(matrix);
	return (matrix);
}
