/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_nav.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:49:05 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/09 02:02:43 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftrl_internal.h"

static void	go_to_point_dumb(unsigned long idx,
							t_point *to,
							t_point *from,
							t_readline *rl)
{
	t_direct		dir;
	unsigned long	pos;

	if (to->y != from->y)
	{
		rl_erase_dumb_line();
		if (to->y == 1 && rl->prompt)
			ft_putstr_fd(rl->prompt, STDIN_FILENO);
		pos = ft_putstrmax_fd(rl->line + g_ws.ws_col * (to->y - 1)
							- ((to->y > 1) ? rl->prlen + 2 : 0),
				g_ws.ws_col - ((to->y == 1) ? rl->prlen : 0) - 2,
				STDIN_FILENO);
		idx--;
		(to->y == 1) ? pos += rl->prlen : pos--;
	}
	else
		pos = from->x;
	dir = to->x > pos ? kDirectRight : kDirectLeft;
	while (pos != to->x)
	{
		ft_putchar_fd((dir == kDirectRight) ? rl->line[idx] : 8, STDIN_FILENO);
		(dir == kDirectRight) ? pos++ : pos--;
		(dir == kDirectRight) ? idx++ : idx--;
	}
}

void		go_to_point(unsigned long idx, \
						t_point *to, \
						t_point *from, \
						t_readline *rl)
{
	char		*tch;
	char		*tcv;
	int			lenh;
	int			lenv;

	if (from->x == to->x && from->y == to->y)
		return ;
	if (rl->dumb)
	{
		go_to_point_dumb(idx, to, from, rl);
		return ;
	}
	tcv = (from->y < to->y) ? rl->movs.downm : rl->movs.upm;
	lenv = (from->y < to->y) ? (int)(to->y - from->y) : (int)(from->y - to->y);
	if (lenv > 0)
		outcap_arg_fb(NULL, tcv, lenv, lenv);
	if (lenv == 0 || tcv == rl->movs.upm)
	{
		tch = (from->x < to->x) ? rl->movs.rightm : rl->movs.leftm;
		lenh = (from->x < to->x) ? (int)(to->x - from->x)
								: (int)(from->x - to->x);
		outcap_arg_fb(NULL, tch, lenh, 1);
		return ;
	}
	outcap_arg_fb(NULL, rl->movs.rightm, (int)to->x, 1);
}

void		go_to_pos(unsigned long to, unsigned long from, t_readline *rl)
{
	t_point		toc;
	t_point		fromc;

	if (to == from)
		return ;
	get_line_info_for_pos(&toc, to, rl);
	get_line_info_for_pos(&fromc, from, rl);
	go_to_point(from, &toc, &fromc, rl);
}
