/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:33:26 by lpousse           #+#    #+#             */
/*   Updated: 2016/04/05 12:42:35 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenmax(t_matrix *m)
{
	int		i;
	int		j;
	int		len;
	int		tmp;

	len = 1;
	i = -1;
	while (++i < m->y)
	{
		j = -1;
		while (++j < m->x)
		{
			tmp = ft_intlen((m->m)[i][j]) + ((m->m)[i][j] < 0);
			len = (tmp > len ? tmp : len);
		}
	}
	return (len);
}

void		ft_putmat(t_matrix *m)
{
	int		i;
	int		j;
	int		len;
	int		space;

	len = lenmax(m);
	i = 0;
	while (i < m->y)
	{
		j = 0;
		while (j < m->x)
		{
			space = len - ft_intlen((m->m)[i][j]);
			while (space-- != 0)
				ft_putchar(' ');
			ft_putdouble((m->m)[i][j]);
			j++;
			if (j != m->x)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		i++;
	}
}
