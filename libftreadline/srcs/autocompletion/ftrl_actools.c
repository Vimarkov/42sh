/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_actools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:24:32 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/02 22:19:37 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ftrl_dev.h"

static void	ft_aclst_rmdups_check(t_list **lst, t_list **bw, t_list *prev)
{
	t_list	**ptr;
	t_list	*chk;

	chk = *lst;
	while (chk && *bw && (*bw)->content && chk != *bw)
	{
		if (ft_strequ(((t_acres*)(*bw)->content)->str,
			((t_acres*)chk->content)->str))
		{
			ptr = (!prev) ? lst : &prev->next;
			*ptr = (*bw)->next;
			ft_lstdelone(bw, &ft_acres_free);
			*bw = prev;
		}
		else
			chk = chk->next;
	}
}

void		ft_aclst_rmdups(t_list **lst)
{
	t_list	*bw;
	t_list	*prev;

	bw = (lst) ? *lst : NULL;
	prev = NULL;
	while (bw)
	{
		ft_aclst_rmdups_check(lst, &bw, prev);
		prev = bw;
		bw = bw->next;
	}
}

void		ft_acres_free(void *content, size_t size)
{
	if (!content || size == 0)
		return ;
	ft_strdel(&((t_acres*)content)->visible_str);
	ft_strdel(&((t_acres*)content)->str);
	free(content);
}

int			ft_acres_sortalpha(t_list *a, t_list *b)
{
	if (!a || !b
		|| !a->content || !b->content
		|| !((t_acres*)a->content)->visible_str
		|| !((t_acres*)b->content)->visible_str)
		return (FALSE);
	if (ft_strcmp(((t_acres*)a->content)->visible_str,
		((t_acres*)b->content)->visible_str) > 0)
		return (TRUE);
	return (FALSE);
}
