/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matidentity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <lpousse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:12:36 by lpousse           #+#    #+#             */
/*   Updated: 2016/04/29 16:39:47 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	*ft_matidentity(int n)
{
	t_matrix	*identity;

	identity = ft_matnew(n, n);
	if (identity == NULL)
		return (NULL);
	while (n > 0)
	{
		n--;
		(identity->m)[n][n] = 1;
	}
	return (identity);
}
