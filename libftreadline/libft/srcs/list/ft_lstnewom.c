/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:01:52 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/28 23:06:01 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnewom(const void *content, size_t content_size)
{
	t_list *lst;

	if (!(lst = (t_list*)ft_memalloc(sizeof(t_list) + content_size)))
		return (NULL);
	if (content)
	{
		lst->content = (void*)((t_uintptr)lst + sizeof(t_list));
		ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
	}
	return (lst);
}
