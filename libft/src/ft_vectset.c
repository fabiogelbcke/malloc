/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:34:56 by lpousse           #+#    #+#             */
/*   Updated: 2016/03/18 14:37:39 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vectset(t_vector *v, double *data)
{
	int		i;

	i = -1;
	while (++i < v->n)
		(v->v)[i] = data[i];
}