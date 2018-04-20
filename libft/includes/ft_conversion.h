/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:20:33 by lpousse           #+#    #+#             */
/*   Updated: 2016/09/21 17:45:57 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSION_H
# define FT_CONVERSION_H

int		ft_atoi(const char *str);
int		ft_atoi_fwd(char **str);
double	ft_atod(const char *str);
char	*ft_itoa(int n);
char	*ft_ltoa(long n);
char	*ft_lltoa(long long n);
char	*ft_htoa(short n);
char	*ft_hhtoa(signed char n);
char	*ft_utoa(unsigned int n);
char	*ft_lutoa(unsigned long n);
char	*ft_llutoa(unsigned long long n);
char	*ft_hutoa(unsigned short n);
char	*ft_hhutoa(unsigned char n);
char	*ft_stoa_base(intmax_t n, int base);
char	*ft_utoa_base(uintmax_t n, int base);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_strupcase(char *str);

#endif
