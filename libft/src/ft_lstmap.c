/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpousse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:03:18 by lpousse           #+#    #+#             */
/*   Updated: 2015/11/30 18:47:27 by lpousse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*f_lst;
	t_list	*f_lsttmp;

	if (lst != NULL && (*f) != NULL)
	{
		if ((f_lst = ft_lstnew(lst->content, lst->content_size)) == NULL)
			return (NULL);
		f_lst = f(f_lst);
		f_lsttmp = f_lst;
		lst = lst->next;
		while (lst)
		{
			f_lsttmp->next = ft_lstnew(lst->content, lst->content_size);
			if (f_lsttmp->next == NULL)
				return (NULL);
			f_lsttmp->next = f(f_lsttmp->next);
			f_lsttmp = f_lsttmp->next;
			lst = lst->next;
		}
		return (f_lst);
	}
	return (NULL);
}
