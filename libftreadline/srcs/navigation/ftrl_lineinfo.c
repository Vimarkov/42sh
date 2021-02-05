/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_lineinfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 04:59:10 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/09 04:33:22 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftrl_internal.h"

inline static void	adapt_multiple_lines(t_point *pt,
										unsigned long pos,
										t_readline *rl)
{
	char			*bw;

	pt->x = rl->prlen;
	bw = rl->line;
	while (*bw && bw != rl->line + pos)
	{
		if (*(bw++) == '\n' || pt->x == g_ws.ws_col - 1)
		{
			pt->y++;
			pt->x = 0;
		}
		else
			pt->x++;
	}
}

void				get_line_info_for_pos(t_point *pt,
										unsigned long pos,
										t_readline *rl)
{
	if (g_ws.ws_col == 0 || g_ws.ws_row == 0)
		return ;
	if (!rl->line || rl->dumb)
	{
		pt->y = (pos + rl->prlen) / (g_ws.ws_col - rl->dumb) + 1;
		pt->x = (pos + rl->prlen) % (g_ws.ws_col - rl->dumb);
		return ;
	}
	pt->y = 1;
	adapt_multiple_lines(pt, pos, rl);
	pt->x = pt->x % g_ws.ws_col;
}

inline void			get_line_info(t_point *pt, t_readline *rl)
{
	get_line_info_for_pos(pt, rl->csr.pos, rl);
}
