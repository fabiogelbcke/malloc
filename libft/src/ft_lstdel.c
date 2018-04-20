/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:12:41 by lpousse           #+#    #+#             */
/*   Updated: 2015/11/30 17:40:05 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*next_lst;

	if (alst)
	{
		lst = *alst;
		while (lst)
		{
			next_lst = lst->next;
			ft_lstdelone(&lst, del);
			lst = next_lst;
		}
		*alst = NULL;
	}
}
