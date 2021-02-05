/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_nomalloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:01:52 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/19 06:25:46 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew_nomalloc(void *content, size_t content_size)
{
	t_list *lst;

	if (!(lst = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		lst->content = content;
		lst->content_size = content_size;
	}
	return (lst);
}
