/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_converters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:43:15 by lpousse           #+#    #+#             */
/*   Updated: 2016/11/25 18:25:16 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		null_converter(char **str, int i, t_specs *s)
{
	char	*new;
	size_t	j;

	if ((s->flags)['.'] == 0 || 6 < s->prec)
		s->prec = 6;
	s->len = ft_umax(s->prec, s->width);
	new = ft_strnew(s->len);
	j = 0;
	if ((s->flags)['-'] == 0)
		while (j + s->prec < s->width)
			new[j++] = (s->flags)['0'] == 0 ? ' ' : '0';
	ft_strncpy(new + j, "(null)", s->prec);
	j += s->prec;
	if ((s->flags)['-'] == 1)
		while (j < s->width)
			new[j++] = ' ';
	return (merge_var(str, new, i, s));
}

int				string_converter(char **str, int i, t_specs *s, va_list ap)
{
	char	*var;
	char	*new;
	size_t	j;

	var = va_arg(ap, char *);
	if (var == NULL)
		return (null_converter(str, i, s));
	if ((s->flags)['.'] == 0 || ft_strlen(var) < s->prec)
		s->prec = ft_strlen(var);
	s->len = ft_umax(s->prec, s->width);
	new = ft_strnew(s->len);
	j = 0;
	if ((s->flags)['-'] == 0)
		while (j + s->prec < s->width)
			new[j++] = (s->flags)['0'] == 0 ? ' ' : '0';
	ft_strncpy(new + j, var, s->prec);
	j += s->prec;
	if ((s->flags)['-'] == 1)
		while (j < s->width)
			new[j++] = ' ';
	return (merge_var(str, new, i, s));
}

static size_t	wstr_prec(wchar_t *s, t_specs *specs)
{
	size_t	size;
	int		i;

	size = ft_wstrsize(s);
	if ((specs->flags)['.'] == 0 || specs->prec > size)
		return (size);
	size = 0;
	i = 0;
	while (size + ft_wcharsize(s[i]) <= specs->prec)
		size += ft_wcharsize(s[i++]);
	return (size);
}

int				wstring_converter(char **str, int i, t_specs *specs, va_list ap)
{
	wchar_t	*s;
	char	*var;
	size_t	j;

	s = va_arg(ap, wchar_t *);
	if (s == NULL)
		return (null_converter(str, i, specs));
	specs->prec = wstr_prec(s, specs);
	specs->len = ft_umax(specs->prec, specs->width);
	var = ft_strnew(specs->len);
	j = 0;
	if ((specs->flags)['-'] == 0)
		while (j + specs->prec < specs->width)
			var[j++] = (specs->flags)['0'] == 0 ? ' ' : '0';
	ft_wstrsizecpy(var + j, s, specs->prec);
	j += specs->prec;
	if ((specs->flags)['-'] == 1)
		while (j < specs->width)
			var[j++] = ' ';
	return (merge_var(str, var, i, specs));
}
