/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_csrutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:10:27 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/07 19:25:21 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ftrl_internal.h"

/*
** Prevent left, home or mov tab left keys if scrolling up
** or redrawing would be necessary.
** This is to prevent a bug in those cases, like with bash's readline (v3.2)
*/

t_uint8				check_height(t_point *gtc, t_readline *rl)
{
	t_point			maxc;
	unsigned long	new_min;

	get_line_info_for_pos(&maxc, rl->csr.max, rl);
	if (maxc.y <= g_ws.ws_row && rl->min_y == 0)
		return (TRUE);
	if (maxc.y > rl->max_y)
		rl->max_y = maxc.y;
	if ((new_min = rl->max_y - g_ws.ws_row) > rl->min_y)
		rl->min_y = new_min;
	return (gtc->y > rl->min_y);
}

/*
** Functions to unselect cpy/paste selected text
*/

inline static void	check_selection_dumb(t_readline *rl)
{
	t_point		spt;
	t_point		ept;

	get_line_info_for_pos(&spt, rl->cpypste.mkrs[0], rl);
	get_line_info_for_pos(&ept, rl->cpypste.mkrs[1], rl);
	if (spt.y == ept.y)
		return ;
	ft_putchar_fd('\r', STDIN_FILENO);
	(void)ft_putstrmax_fd(rl->line + rl->cpypste.mkrs[1] - ept.x,
						ept.x + 1, STDIN_FILENO);
}

void				check_selection(t_readline *rl)
{
	if (rl->cpypste.mkrs[0] == 0 && rl->cpypste.mkrs[1] == 0)
		return ;
	if (rl->dumb)
		check_selection_dumb(rl);
	else
	{
		go_to_pos(rl->cpypste.mkrs[0], rl->csr.pos, rl);
		ft_putstrmax_fd(rl->line + rl->cpypste.mkrs[0],
			rl->cpypste.mkrs[1] - rl->cpypste.mkrs[0], STDIN_FILENO);
		go_to_pos(rl->csr.pos, rl->cpypste.mkrs[1], rl);
	}
	rl->cpypste.cpyed = FALSE;
	rl->cpypste.idx = 0;
	ft_bzero(rl->cpypste.mkrs, sizeof(rl->cpypste.mkrs));
}
