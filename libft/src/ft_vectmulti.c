/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectmulti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 13:35:26 by lpousse           #+#    #+#             */
/*   Updated: 2016/03/18 14:03:49 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vectmulti(t_vector *a, t_vector *b)
{
	t_vector	*result;

	if (a->n != 3 || b->n != 3 || !(result = ft_vectnew(3)))
		return (NULL);
	(result->v)[0] = (a->v)[1] * (b->v)[2] - (a->v)[2] * (b->v)[1];
	(result->v)[1] = (a->v)[2] * (b->v)[0] - (a->v)[0] * (b->v)[2];
	(result->v)[2] = (a->v)[0] * (b->v)[1] - (a->v)[1] * (b->v)[0];
	return (result);
}
