/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectmulti_scal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:04:19 by lpousse           #+#    #+#             */
/*   Updated: 2016/03/18 14:08:22 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vectmulti_scal(t_vector *a, double b)
{
	t_vector	*result;
	int			i;

	if (!(result = ft_vectnew(a->n)))
		return (0);
	i = -1;
	while (++i < a->n)
		(result->v)[i] = (a->v)[i] * b;
	return (result);
}
