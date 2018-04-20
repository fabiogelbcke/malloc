/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:23:03 by lpousse           #+#    #+#             */
/*   Updated: 2016/11/30 19:44:54 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <wchar.h>
# include "ft_conversion.h"
# include "ft_is.h"
# include "ft_list.h"
# include "ft_matrix.h"
# include "ft_memory.h"
# include "ft_number.h"
# include "ft_put.h"
# include "ft_str.h"
# include "ft_wstr.h"

int				ft_gnl(int const fd, char **line);
int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_asprintf(char **ret, const char *format, ...);

#endif
