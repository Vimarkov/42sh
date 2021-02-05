/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:23:06 by kdumarai          #+#    #+#             */
/*   Updated: 2017/11/16 18:27:02 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	if (!(tmp = ft_lstnew(new->content, new->content_size)))
		return (NULL);
	ret = tmp;
	lst = lst->next;
	while (lst)
	{
		new = f(lst);
		if (!(tmp->next = ft_lstnew(new->content, new->content_size)))
			return (NULL);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (ret);
}
