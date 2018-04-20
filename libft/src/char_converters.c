/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_converters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 16:50:48 by lpousse           #+#    #+#             */
/*   Updated: 2016/11/25 18:28:01 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		char_converter(char **str, int i, t_specs *specs, va_list ap)
{
	char	c;
	char	*var;
	size_t	j;

	if (specs->conv == '%')
		c = (char)specs->len;
	else
		c = (char)va_arg(ap, int);
	specs->len = ft_umax(1, specs->width);
	var = ft_strnew(specs->len);
	j = 0;
	if ((specs->flags)['0'] == 0 && (specs->flags)['-'] == 0)
		while (j + 1 < specs->width)
			var[j++] = ' ';
	if ((specs->flags)['0'] == 1 && (specs->flags)['-'] == 0)
		while (j + 1 < specs->width)
			var[j++] = '0';
	var[j++] = c;
	if ((specs->flags)['-'] == 1)
		while (j < specs->width)
			var[j++] = ' ';
	if (merge_var(str, var, i, specs) < 0)
		return (-1);
	return (specs->len);
}

int		wchar_converter(char **str, int i, t_specs *specs, va_list ap)
{
	wint_t	c;
	char	*var;
	size_t	j;
	int		tlen;

	c = va_arg(ap, wint_t);
	specs->len = ft_wcharsize(c);
	tlen = ft_umax(specs->len, specs->width);
	var = ft_strnew(specs->len);
	j = 0;
	if ((specs->flags)['-'] == 0)
		while (j + specs->len < specs->width)
			var[j++] = (specs->flags)['0'] == 0 ? ' ' : '0';
	ft_wcharcpy(var + j, c);
	j += specs->len;
	if ((specs->flags)['-'] == 1)
		while (j < specs->width)
			var[j++] = ' ';
	specs->len = tlen;
	if (merge_var(str, var, i, specs) < 0)
		return (-1);
	return (tlen);
}
