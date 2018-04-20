/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isincluded.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:13:16 by lpousse           #+#    #+#             */
/*   Updated: 2016/05/19 16:16:08 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isincluded(int n, int a, int b)
{
	if (n >= ft_min(a, b) && n <= ft_max(a, b))
		return (1);
	return (0);
}