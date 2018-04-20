/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:52:12 by lpousse           #+#    #+#             */
/*   Updated: 2016/11/25 18:21:21 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/types.h>
# include <wchar.h>
# include "libft.h"

# define FLAGS "sSpdDioOuUxXbcC"

typedef struct	s_specs
{
	char	flags[128];
	size_t	width;
	size_t	prec;
	char	conv;
	size_t	flag_len;
	size_t	len;
}				t_specs;

typedef int		(*t_conv)(char **, int, t_specs *, va_list);

int				parse_flags(va_list ap, char *str, t_specs *specs);
int				merge_var(char **str, char *var, int i, t_specs *specs);

int				int_converter(char **str, int i, t_specs *specs, va_list ap);
int				uint_converter(char **str, int i, t_specs *specs, va_list ap);
int				char_converter(char **str, int i, t_specs *specs, va_list ap);
int				wchar_converter(char **str, int i, t_specs *specs, va_list ap);
int				string_converter(char **str, int i, t_specs *specs, va_list ap);
int				wstring_converter(char **str, int i, t_specs *sp, va_list ap);
int				pointer_converter(char **str, int i, t_specs *sp, va_list ap);

#endif
