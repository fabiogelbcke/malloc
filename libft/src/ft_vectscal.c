/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectscal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:08:51 by lpousse           #+#    #+#             */
/*   Updated: 2016/03/18 14:17:14 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_vectscal(t_vector *a, t_vector *b)
{
	double	result;
	int		i;

	if (a->n != b->n)
		return (0);
	i = -1;
	result = 0;
	while (++i < a->n)
		result += (a->v)[i] * (b->v)[i];
	return (result);
}
