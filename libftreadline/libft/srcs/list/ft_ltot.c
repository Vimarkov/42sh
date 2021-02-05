/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 03:58:35 by kdumarai          #+#    #+#             */
/*   Updated: 2018/02/18 04:08:43 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_ltot(t_list *lst)
{
	char	**ret;
	char	**bw;

	if (!lst || !(ret = (char**)malloc(sizeof(char*) * (ft_lstlen(lst) + 1))))
		return (NULL);
	bw = ret;
	while (lst)
	{
		if (!(*bw = ft_strdup(lst->content)))
		{
			ft_tabfree(&ret);
			return (NULL);
		}
		bw++;
		lst = lst->next;
	}
	*bw = NULL;
	return (ret);
}
