/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:46:58 by lpousse           #+#    #+#             */
/*   Updated: 2016/11/25 18:25:38 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_left_part(char *new, char *n, size_t *j, t_specs *s)
{
	if ((s->flags)['0'] == 0 && (s->flags)['-'] == 0)
		while (*j + s->len < s->width)
			new[(*j)++] = ' ';
	if (n[0] == '-')
		new[(*j)++] = '-';
	else if ((s->flags)['+'])
		new[(*j)++] = '+';
	else if ((s->flags)[' '])
		new[(*j)++] = ' ';
	if ((s->flags)['0'])
		while (*j + ft_strlen(n) - (n[0] == '-') < s->width)
			new[(*j)++] = '0';
}

static void	add_int(char *new, char *n, t_specs *s, intmax_t nb)
{
	size_t	j;

	j = 0;
	add_left_part(new, n, &j, s);
	if ((s->flags)['.'] > 0)
	{
		while ((s->prec)-- > ft_strlen(n) - (n[0] == '-'))
			new[j++] = '0';
		s->prec = 1;
	}
	if (nb != 0 || (s->flags)['.'] == 0 || s->prec != 0)
	{
		ft_strcpy(new + j, n + (n[0] == '-'));
		j += ft_strlen(n) - (n[0] == '-');
	}
	if ((s->flags)['-'] == 1)
		while (j < s->width)
			new[j++] = ' ';
	ft_strdel(&n);
}

static int	int_flags(char **str, int i, intmax_t n, t_specs *specs)
{
	char	*var;
	char	*nb;
	int		tlen;

	specs->len = ft_umax(ft_intmaxlen_base(n, 10), specs->prec);
	if ((specs->flags)['-'] || (specs->flags)['.'])
		(specs->flags)['0'] = 0;
	if (n < 0 || (specs->flags)['+'] || (specs->flags)[' '])
		(specs->len)++;
	if (n == 0 && (specs->flags)['.'] && specs->prec == 0)
		(specs->len)--;
	tlen = ft_umax(specs->len, specs->width);
	var = ft_strnew(tlen);
	nb = ft_stoa_base(n, 10);
	if (!var || !nb)
		return (-1);
	add_int(var, nb, specs, n);
	specs->len = tlen;
	if (merge_var(str, var, i, specs) < 0)
		return (-1);
	return (tlen);
}

int			int_converter(char **str, int i, t_specs *specs, va_list ap)
{
	intmax_t	n;

	n = va_arg(ap, intmax_t);
	if ((specs->flags)['l'] + (specs->conv == 'D') >= 2)
		n = (long long)n;
	else if ((specs->flags)['l'] + (specs->conv == 'D') == 1)
		n = (long)n;
	else if ((specs->flags)['h'] == 1)
		n = (short)n;
	else if ((specs->flags)['h'] >= 2)
		n = (signed char)n;
	else if ((specs->flags)['z'] > 0)
		n = (ssize_t)n;
	else if ((specs->flags)['j'] < 1)
		n = (int)n;
	return (int_flags(str, i, n, specs));
}
