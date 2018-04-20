/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:10:45 by lpousse           #+#    #+#             */
/*   Updated: 2016/09/21 17:20:00 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WSTR_H
# define FT_WSTR_H

size_t	ft_wstrlen(wchar_t *wstr);
size_t	ft_wcharsize(wchar_t c);
size_t	ft_wstrsize(const wchar_t *wstr);
void	ft_wcharcpy(char *str, wchar_t c);
void	ft_wstrcpy(wchar_t *dest, const wchar_t *src);
void	ft_wstrsizecpy(char *str, wchar_t *wstr, size_t size);
wchar_t	*ft_wstrdup(const wchar_t *src);

#endif
