/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:25:50 by lpousse           #+#    #+#             */
/*   Updated: 2016/01/11 14:25:48 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		i;
	int		nb;
	int		neg;

	i = 0;
	nb = 0;
	neg = 0;
	while ((str[i] == '\f' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == ' ' || str[i] == '\n' || str[i] == '\r') && str[i] != 0)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		neg = (str[i] == '-');
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (neg ? -nb : nb);
}