/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_fwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:59:06 by lpousse           #+#    #+#             */
/*   Updated: 2016/09/27 17:31:23 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_fwd(char **str)
{
	int		nb;
	int		neg;

	nb = 0;
	neg = 0;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		neg = (**str == '-');
	}
	while (**str >= '0' && **str <= '9')
	{
		nb = nb * 10 + **str - 48;
	}
	return (neg ? -nb : nb);
}
