/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mattransp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:33:45 by lpousse           #+#    #+#             */
/*   Updated: 2016/03/17 16:55:58 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	*ft_mattransp(t_matrix *m)
{
	t_matrix	*transp;
	int			i;
	int			j;

	if (!(transp = ft_matnew(m->y, m->x)))
		return (NULL);
	i = -1;
	while (++i < transp->y)
	{
		j = -1;
		while (++j < transp->x)
			(transp->m)[i][j] = (m->m)[j][i];
	}
	return (transp);
}
