/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_linekeys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:45:50 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/15 20:11:09 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftrl_internal.h"

t_keyact	rl_input_add_text(char *buff, t_readline *rl)
{
	char			add[RL_READBUFFSIZE + 1];
	unsigned short	idx;

	if (*buff == 27)
		return (kKeyNone);
	idx = 0;
	ft_bzero(add, sizeof(add));
	while (*buff)
	{
		if (ft_isprint(*buff) || (*buff == '\n' && !rl->dumb))
			add[idx++] = *buff;
		buff++;
	}
	if (!rl_line_add(add, rl))
		return (kKeyFatal);
	return ((idx > 0) ? kKeyOK : kKeyFail);
}

t_keyact	rl_input_rm_text(char *buff, t_readline *rl)
{
	int				keys[2];
	t_keyact		status;

	keys[0] = ft_strequ(buff, ESC_BACKSPACE);
	keys[1] = ft_strequ(buff, rl->keys.delk);
	if (!keys[0] && !keys[1])
		return (kKeyNone);
	if (keys[0] && rl->csr.pos > 0)
		return ((rl_line_rm(1, rl)) ? kKeyOK : kKeyFatal);
	else if (keys[1] && rl->csr.pos < rl->csr.max)
	{
		if ((status = rl_right_key(rl)) >= kKeyFail || !rl_line_rm(1, rl))
			return ((status == kKeyOK) ? kKeyFatal : status);
		return (kKeyOK);
	}
	return (kKeyFail);
}

t_keyact	rl_clear_line(t_readline *rl)
{
	t_point		coords;
	t_point		homec;
	t_point		maxc;

	if (rl->dumb)
		return (kKeyFail);
	get_line_info(&coords, rl);
	if (coords.y >= g_ws.ws_row)
		return (kKeyFail);
	get_line_info_for_pos(&homec, 0, rl);
	get_line_info_for_pos(&maxc, rl->csr.max, rl);
	go_to_point(rl->csr.pos, &homec, &coords, rl);
	(void)outcapstr(rl->movs.crcap);
	(void)outcap_arg_fb(rl->movs.dlargcap, rl->movs.dlcap,
						(int)maxc.y, (int)maxc.y);
	(void)outcapstr(rl->movs.cecap);
	free(rl->line);
	if (!rl_linebuff_create(rl))
		return (kKeyFatal);
	ft_putstr_fd(rl->prompt, rl->opts->outfd);
	ft_bzero(&rl->csr, sizeof(t_cursor));
	return (kKeyOK);
}

t_keyact	rl_eof_key(t_readline *rl)
{
	t_keyact	status;

	if (rl->csr.max == 0)
	{
		rl->ret = FTRL_EOF;
		ft_strdel(&rl->line);
		return (kKeyOK);
	}
	if (rl->csr.pos >= rl->csr.max)
		return (kKeyFail);
	if ((status = rl_right_key(rl)) != kKeyOK || !rl_line_rm(1, rl))
		return ((status == kKeyOK) ? kKeyFatal : status);
	return (kKeyOK);
}

t_keyact	rl_clscr_key(t_readline *rl)
{
	char	*ptr;

	if (rl->dumb || !(ptr = tgetstr("cl", NULL))
		|| tputs(ptr, (int)g_ws.ws_row, &putcf) == -1)
		return (kKeyFail);
	rl->quit.reason = kAbortClear;
	return (kKeyOK);
}
