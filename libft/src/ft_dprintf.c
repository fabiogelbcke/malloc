/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:51:53 by lpousse           #+#    #+#             */
/*   Updated: 2016/11/30 20:01:37 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_converter_tab(t_conv *tab)
{
	tab['s'] = &string_converter;
	tab['S'] = &wstring_converter;
	tab['p'] = &pointer_converter;
	tab['d'] = &int_converter;
	tab['D'] = &int_converter;
	tab['i'] = &int_converter;
	tab['o'] = &uint_converter;
	tab['O'] = &uint_converter;
	tab['u'] = &uint_converter;
	tab['U'] = &uint_converter;
	tab['x'] = &uint_converter;
	tab['X'] = &uint_converter;
	tab['b'] = &uint_converter;
	tab['c'] = &char_converter;
	tab['C'] = &wchar_converter;
	tab['%'] = &char_converter;
}

static t_conv	get_converter(char c)
{
	static t_conv	*tab = NULL;

	if (tab == NULL)
	{
		tab = (t_conv *)ft_memalloc(sizeof(t_conv) * 128);
		if (tab != NULL)
			set_converter_tab(tab);
		else
			return (NULL);
	}
	return (tab[(int)c]);
}

static int		add_var(va_list ap, char **str, int *i)
{
	int		len;
	t_specs	specs;
	t_conv	converter;

	ft_bzero(specs.flags, 128);
	specs.width = 0;
	specs.prec = 0;
	specs.conv = 0;
	if (parse_flags(ap, *str + *i + 1, &specs) < 0)
	{
		len = merge_var(str, NULL, *i, &specs);
		*i -= 1;
		return (len);
	}
	if ((specs.flags)['l'] > 0
		&& (specs.conv == 'c' || specs.conv == 's'))
		specs.conv -= 32;
	converter = get_converter(specs.conv);
	len = converter(str, *i, &specs, ap);
	if (len < 0)
		return (-1);
	*i += len - 1;
	return (0);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	char		*str;
	int			i;

	va_start(ap, format);
	i = 0;
	if (!(str = ft_strdup(format)))
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && add_var(ap, &str, &i) < 0)
			return (-1);
		i++;
	}
	va_end(ap);
	ft_putnstr_noend_fd(str, i, fd);
	free(str);
	return (i);
}
