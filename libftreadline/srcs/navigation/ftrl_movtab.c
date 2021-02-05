/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_movtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 00:22:58 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/08 05:40:18 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftrl_internal.h"

static t_uint8	move_to_next_tab(t_readline *rl, int direct)
{
	unsigned long	pos;
	t_point			newpoint;
	t_point			coords;

	pos = rl->csr.pos - (rl->csr.pos > 0 && direct == kDirectLeft);
	while (((pos > 0 && direct == kDirectLeft)
		|| (rl->line[pos] && direct == kDirectRight))
		&& !ft_isalpha(rl->line[pos]))
		(direct == kDirectRight) ? pos++ : pos--;
	while (((pos > 0 && direct == kDirectLeft)
		|| (rl->line[pos] && direct == kDirectRight))
		&& ft_isalpha(rl->line[pos]))
		(direct == kDirectRight) ? pos++ : pos--;
	if (pos > 0 && direct == kDirectLeft)
		pos++;
	get_line_info(&coords, rl);
	get_line_info_for_pos(&newpoint, pos, rl);
	if (!check_height(&newpoint, rl))
		return (FALSE);
	go_to_point(rl->csr.pos, &newpoint, &coords, rl);
	rl->csr.pos = pos;
	rl->prefered_x = newpoint.x;
	return (TRUE);
}

t_keyact		rl_movl_key(t_readline *rl)
{
	if (rl->csr.pos <= 0)
		return (kKeyFail);
	return ((move_to_next_tab(rl, kDirectLeft)) ? kKeyOK : kKeyFail);
}

t_keyact		rl_movr_key(t_readline *rl)
{
	if (rl->csr.pos >= rl->csr.max)
		return (kKeyFail);
	return ((move_to_next_tab(rl, kDirectRight)) ? kKeyOK : kKeyFail);
}
