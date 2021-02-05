/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_linemov.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 03:40:54 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/09 04:28:17 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftrl_internal.h"

static unsigned long	point_to_idx(t_point *pt, t_readline *rl)
{
	t_point			chkpt;
	unsigned long	ret;

	if (pt->x < rl->prlen && pt->y == 1)
		return (0);
	chkpt.y = 1;
	chkpt.x = rl->prlen;
	ret = 0;
	while ((chkpt.y != pt->y || chkpt.x != pt->x) && rl->line[ret])
	{
		if (rl->line[ret] == '\n' || chkpt.x == g_ws.ws_col - 1)
		{
			if (chkpt.y == pt->y && chkpt.x != pt->x)
				break ;
			chkpt.y++;
			chkpt.x = 0;
		}
		else
			chkpt.x++;
		ret++;
	}
	return (ret);
}

static t_uint8			chg_line(t_readline *rl, t_direct direct)
{
	t_point			coords;
	t_point			maxc;
	unsigned long	idx;

	get_line_info(&coords, rl);
	if (coords.y <= 1 && direct == kDirectLeft)
		return (FALSE);
	if (direct == kDirectRight)
	{
		get_line_info_for_pos(&maxc, rl->csr.max, rl);
		if (coords.y >= maxc.y)
			return (FALSE);
	}
	(direct == kDirectLeft) ? coords.y-- : coords.y++;
	coords.x = rl->prefered_x;
	idx = point_to_idx(&coords, rl);
	go_to_pos(idx, rl->csr.pos, rl);
	rl->csr.pos = idx;
	return (TRUE);
}

t_keyact				rl_moveline_up(t_readline *rl)
{
	if (rl->dumb || !chg_line(rl, kDirectLeft))
		return (kKeyFail);
	return (kKeyOK);
}

t_keyact				rl_moveline_down(t_readline *rl)
{
	if (rl->dumb || !chg_line(rl, kDirectRight))
		return (kKeyFail);
	return (kKeyOK);
}
