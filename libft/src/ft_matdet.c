/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matdet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:36:36 by lpousse           #+#    #+#             */
/*   Updated: 2016/04/05 15:19:56 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_matdet(t_matrix *m)
{
	t_matrix	*subm;
	double		det;
	int			i;

	if (m->x != m->y)
		return (0);
	if (m->x == 1)
		return ((m->m)[0][0]);
	if (m->x == 2)
		return ((m->m)[0][0] * (m->m)[1][1] - (m->m)[0][1] * (m->m)[1][0]);
	if (!(subm = ft_matnew(m->x - 1, m->y - 1)))
		return (0);
	det = 0;
	i = 0;
	while (i < m->x)
	{
		ft_matsetsub(subm, m, 0, i);
		if (i % 2 == 0)
			det += (m->m)[0][i] * ft_matdet(subm);
		else
			det -= (m->m)[0][i] * ft_matdet(subm);
		i++;
	}
	ft_matdel(&subm);
	return (det);
}
