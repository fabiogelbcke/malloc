/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 13:30:59 by lpousse           #+#    #+#             */
/*   Updated: 2016/03/18 13:34:08 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vectadd(t_vector *a, t_vector *b)
{
	t_vector	*result;
	int			i;

	if (a->n != b->n || !(result = ft_vectnew(a->n)))
		return (NULL);
	i = -1;
	while (++i < result->n)
		(result->v)[i] = (a->v)[i] + (b->v)[i];
	return (result);
}
