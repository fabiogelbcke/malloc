/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 12:46:43 by lpousse           #+#    #+#             */
/*   Updated: 2016/09/22 19:01:27 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_width(va_list ap, char *str, t_specs *specs)
{
	if (ft_isdigit(*str))
	{
		specs->width = ft_atoi(str);
		return (ft_intlen(specs->width) - 1);
	}
	specs->width = va_arg(ap, int);
	return (0);
}

static int	get_prec(va_list ap, char *str, t_specs *specs)
{
	if (ft_isdigit(*str))
	{
		specs->prec = ft_atoi(str);
		return (ft_intlen(specs->prec));
	}
	else if (*str == '*')
	{
		specs->prec = va_arg(ap, int);
		return (1);
	}
	return (0);
}

static int	get_conv(char *str, int i, t_specs *specs)
{
	if (ft_isoneof(str[i], FLAGS))
		specs->conv = str[i];
	else if (str[i] != '\0')
	{
		specs->conv = '%';
		specs->len = (size_t)str[i];
	}
	else
	{
		specs->flag_len -= 1;
		return (-1);
	}
	return (0);
}

int			parse_flags(va_list ap, char *str, t_specs *specs)
{
	int		i;

	i = 0;
	while (ft_isoneof(str[i], "# -+lhzj.") || ft_isdigit(str[i]))
	{
		specs->flags[(int)str[i]] += 1;
		if ((str[i] > '0' && str[i] <= '9') || str[i] == '*')
			i += get_width(ap, str + i, specs);
		if (str[i] == '.')
			i += get_prec(ap, str + i + 1, specs);
		i++;
	}
	specs->flag_len = i + 2;
	return (get_conv(str, i, specs));
}
