/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matinvert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:27:02 by lpousse           #+#    #+#             */
/*   Updated: 2016/04/05 15:20:37 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_matrix	*minorsmatrix(t_matrix *m)
{
	t_matrix	*invert;
	t_matrix	*subm;
	int			i;
	int			j;

	if (!(invert = ft_matnew(m->x, m->y))
		|| !(subm = ft_matnew(m->x - 1, m->y - 1)))
		return (NULL);
	i = 0;
	while (i < m->y)
	{
		j = 0;
		while (j < m->x)
		{
			ft_matsetsub(subm, m, i, j);
			(invert->m)[i][j] = ft_matdet(subm);
			j++;
		}
		i++;
	}
	return (invert);
}

t_matrix		*ft_matinvert(t_matrix *m)
{
	t_matrix	*invert;
	t_matrix	*final;
	double		det;
	int			i;
	int			j;

	if (m->x != m->y || !(invert = minorsmatrix(m)))
		return (NULL);
	det = 0;
	i = -1;
	while (++i < m->x)
		det += (-2 * (i % 2) + 1) * (m->m)[0][i] * (invert->m)[0][i];
	if (det == 0)
		return (NULL);
	i = -1;
	while (++i < invert->y)
	{
		j = -1;
		while (++j < invert->x)
			(invert->m)[i][j] *= ((-2 * ((i + j) % 2) + 1) * (1 / det));
	}
	final = ft_mattransp(invert);
	ft_matdel(&invert);
	return (final);
}
