/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_converters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 20:37:33 by lpousse           #+#    #+#             */
/*   Updated: 2016/11/25 18:26:00 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_left_part(char *new, char *n, t_specs *s, size_t *j)
{
	if ((s->flags)['0'] == 0 && (s->flags)['-'] == 0)
		while (*j + s->len < s->width)
			new[(*j)++] = ' ';
	if ((s->flags)['#'] > 0 && (s->conv == 'x' || s->conv == 'X')
		&& n[0] != '0')
	{
		new[(*j)++] = '0';
		new[(*j)++] = s->conv;
	}
	if ((s->flags)['0'] && !((s->flags)['-']) && !((s->flags)['.']))
		while (*j + s->prec < s->width && *j + ft_strlen(n) < s->width)
			new[(*j)++] = '0';
}

static void	add_uint(char *new, char *n, t_specs *s, uintmax_t nb)
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
}

static int	base_and_sharp(uintmax_t n, t_specs *s)
{
	char	conv;
	int		base;

	conv = ft_tolower(s->conv);
	base = 10;
	if (conv == 'o')
		base = 8;
	else if (conv == 'x')
		base = 16;
	else if (conv == 'b')
		base = 2;
	s->len = ft_uintmaxlen_base(n, base);
	if ((s->flags)['#'] > 0 && (s->conv == 'o' || s->conv == 'O')
		&& s->prec <= s->len)
		s->prec = s->len + (n != 0);
	s->len = ft_umax(s->len, s->prec);
	if ((s->flags)['#'] > 0 && (s->conv == 'x' || s->conv == 'X') && n != 0)
		s->len += 2;
	return (base);
}

static int	uint_flags(char **str, int i, uintmax_t n, t_specs *s)
{
	char	*var;
	char	*nb;
	int		tlen;
	int		base;

	base = base_and_sharp(n, s);
	if (n == 0 && (s->flags)['.'] && s->prec == 0)
		(s->len)--;
	tlen = ft_umax(s->len, s->width);
	var = ft_strnew(tlen);
	nb = ft_utoa_base(n, base);
	if (s->conv == 'X')
		ft_strupcase(nb);
	if (!var || !nb)
		return (-1);
	add_uint(var, nb, s, n);
	s->len = tlen;
	ft_strdel(&nb);
	if (merge_var(str, var, i, s) < 0)
		return (-1);
	return (tlen);
}

int			uint_converter(char **str, int i, t_specs *specs, va_list ap)
{
	uintmax_t	n;

	n = va_arg(ap, uintmax_t);
	if (specs->conv == 'p')
	{
		n = (unsigned long)n;
		(specs->flags)['#'] += 1;
		specs->conv = 'x';
	}
	else if ((specs->flags)['l']
				+ (specs->conv == 'U' || specs->conv == 'O') >= 2)
		n = (unsigned long long)n;
	else if ((specs->flags)['l'] + (specs->conv == 'U')
						+ (specs->conv == 'O') == 1)
		n = (unsigned long)n;
	else if ((specs->flags)['h'] == 1)
		n = (unsigned short)n;
	else if ((specs->flags)['h'] >= 2)
		n = (unsigned char)n;
	else if ((specs->flags)['z'] > 0)
		n = (size_t)n;
	else if ((specs->flags)['j'] < 1)
		n = (unsigned int)n;
	return (uint_flags(str, i, n, specs));
}
