/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:55:05 by lpousse           #+#    #+#             */
/*   Updated: 2016/09/14 19:48:40 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NUMBER_H
# define FT_NUMBER_H

int		ft_intlen(int n);
int		ft_intlen_base(int n, int base);
size_t	ft_intmaxlen_base(intmax_t n, int base);
size_t	ft_uintmaxlen_base(uintmax_t n, unsigned int base);
void	ft_swap(int *a, int *b);
void	ft_uswap(unsigned int *a, unsigned int *b);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_umax(unsigned int a, unsigned int b);
int		ft_umin(unsigned int a, unsigned int b);
int		ft_abs(int n);
int		ft_pow(int nb, unsigned int pwr);

#endif
