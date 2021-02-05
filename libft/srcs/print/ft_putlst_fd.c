/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:05:02 by kdumarai          #+#    #+#             */
/*   Updated: 2018/01/30 01:27:31 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst_fd(t_list *lst, int fd)
{
	while (lst)
	{
		if (lst->content)
			ft_putendl_fd((char*)lst->content, fd);
		lst = lst->next;
	}
}
