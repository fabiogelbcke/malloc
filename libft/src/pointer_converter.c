/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 22:07:18 by lpousse           #+#    #+#             */
/*   Updated: 2016/11/25 18:26:38 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_left_part(char *new, char *n, t_specs *s, size_t *j)
{
	if ((s->flags)['0'] == 0 && (s->flags)['-'] == 0)
		while (*j + s->len < s->width)
			new[(*j)++] = ' ';
	new[(*j)++] = '0';
	new[(*j)++] = 'x';
	if ((s->flags)['0'] && !((s->flags)['-']) && !((s->flags)['.']))
		while (*j + ft_strlen(n) < s->width)
			new[(*j)++] = '0';
}

static void	add_pointer(char *new, char *n, t_specs *s, unsigned long nb)
{
	size_t	j;

	j = 0;
	add_left_part(new, n, s, &j);
	if (s->prec > 0)
	{
		while ((s->prec)-- > ft_strlen(n))
			new[j++] = '0';
		s->prec = 1;
	}
	if (nb != 0 || (s->flags)['.'] == 0 || s->prec != 0)
	{
		ft_strcpy(new + j, n);
		j += ft_strlen(n);
	}
	if ((s->flags)['-'] == 1)
		while (j < s->width)
			new[j++] = ' ';
	ft_strdel(&n);
}

int			pointer_converter(char **str, int i, t_specs *s, va_list ap)
{
	unsigned long	n;
	char			*var;
	char			*nb;
	int				tlen;

	n = va_arg(ap, unsigned long);
	s->len = ft_umax(ft_uintmaxlen_base(n, 16), s->prec) + 2;
	if (n == 0 && (s->flags)['.'] && s->prec == 0)
		(s->len)--;
	tlen = ft_umax(s->len, s->width);
	var = ft_strnew(tlen);
	nb = ft_utoa_base(n, 16);
	if (!var || !nb)
		return (-1);
	add_pointer(var, nb, s, n);
	s->len = tlen;
	if (merge_var(str, var, i, s) < 0)
		return (-1);
	return (tlen);
}
