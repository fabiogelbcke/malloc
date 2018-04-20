/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 13:23:48 by lpousse           #+#    #+#             */
/*   Updated: 2016/03/18 13:26:54 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vectnew(int n)
{
	t_vector	*vector;

	if (!(vector = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	if (!(vector->v = (double *)malloc(sizeof(double) * n)))
		return (NULL);
	vector->n = n;
	return (vector);
}
