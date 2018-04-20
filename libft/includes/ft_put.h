/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:05:59 by lpousse           #+#    #+#             */
/*   Updated: 2016/09/27 17:26:13 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_H
# define FT_PUT_H

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putnstr(char *str, size_t n);
void	ft_putendl(char const *s);
void	ft_putnstr_noend(char const *s, size_t n);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd (char const *s, int fd);
void	ft_putnstr_fd(char *str, size_t n, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnstr_noend_fd(char const *s, size_t n, int fd);

void	ft_putnbr(int n);
void	ft_putlong(long n);
void	ft_putnbr_base(int n, int base);
void	ft_putintmax(intmax_t n);
void	ft_putintmaxns(intmax_t n);
void	ft_puts_base(intmax_t n, int base);
void	ft_puts_base_caps(intmax_t n, int base);
void	ft_putu_base(uintmax_t n, unsigned int base);
void	ft_putu_base_caps(uintmax_t n, unsigned int base);

void	ft_putintmaxns_fd(intmax_t n, int fd);
void	ft_putu_base_fd(uintmax_t n, unsigned int base, int fd);
void	ft_putu_base_caps_fd(uintmax_t n, unsigned int base, int fd);

void	ft_putdouble(double n);

void	ft_putwchar(wchar_t c);
void	ft_putwstr(wchar_t *wstr);
void	ft_putnwstr(wchar_t *wstr, size_t n);
void	ft_putsizewstr(wchar_t *wstr, size_t size);

void	ft_putwchar_fd(wchar_t c, int fd);
void	ft_putwstr_fd(wchar_t *wstr, int fd);
void	ft_putnwstr_fd(wchar_t *wstr, size_t n, int fd);
void	ft_putsizewstr_fd(wchar_t *wstr, size_t size, int fd);

void	ft_putmat(t_matrix *m);

#endif
