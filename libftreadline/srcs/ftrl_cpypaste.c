/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_cpypaste.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:03:06 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/08 05:47:01 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftrl_internal.h"

/*
** Left Selection (Shift + Left)
*/

t_keyact	rl_leftcpy_key(t_readline *rl)
{
	if (!rl || rl->cpypste.mkrs[1] <= rl->cpypste.mkrs[0]
		|| rl->cpypste.mkrs[1] == 0)
		return (kKeyFail);
	(void)rl_left_key(rl);
	ft_putchar_fd(rl->line[rl->csr.pos], STDIN_FILENO);
	rl->csr.pos++;
	(void)rl_left_key(rl);
	rl->cpypste.mkrs[1]--;
	if (rl->cpypste.mkrs[0] == rl->cpypste.mkrs[1])
		rl->cpypste.idx = 0;
	return (kKeyOK);
}

/*
** Right Selection (Shift + Right)
*/

t_keyact	rl_rightcpy_key(t_readline *rl)
{
	t_point			pos;

	if (!rl || rl->csr.pos >= rl->csr.max)
		return (kKeyFail);
	rl->cpypste.mkrs[rl->cpypste.idx] = rl->csr.pos + (rl->cpypste.idx == 1);
	rl->cpypste.idx = 1;
	get_line_info(&pos, rl);
	if (rl->dumb)
	{
		if (pos.x + 2 == g_ws.ws_col)
			go_to_pos(rl->csr.pos + 1, rl->csr.pos, rl);
		ft_putchar_fd((char)ft_toupper(rl->line[rl->csr.pos]), STDIN_FILENO);
	}
	else
	{
		(void)outcap("mr");
		ft_putchar_fd(rl->line[rl->csr.pos], STDIN_FILENO);
		(void)outcap("me");
	}
	rl->csr.pos++;
	rl->prefered_x = pos.x;
	return (kKeyOK);
}

/*
** Copy/Cut Selection (Shift + Up once or twice)
*/

t_keyact	rl_cpy_key(t_readline *rl)
{
	char	*cpy;
	size_t	len;

	if (!rl || !*rl->line || !(len = rl->cpypste.mkrs[1] - rl->cpypste.mkrs[0]))
		return (kKeyFail);
	if (!(cpy = ft_strsub(rl->line, (unsigned int)rl->cpypste.mkrs[0], len)))
		return (kKeyFatal);
	if (ft_strequ(rl->cpypste.dat, cpy) && rl->cpypste.cpyed)
	{
		go_to_pos(rl->cpypste.mkrs[1], rl->csr.pos, rl);
		free(cpy);
		rl->cpypste.cpyed = FALSE;
		if (!rl_line_rm(len, rl))
			return (kKeyFatal);
	}
	else
	{
		go_to_pos(rl->cpypste.mkrs[0], rl->csr.pos, rl);
		ft_putstr_fd(cpy, STDIN_FILENO);
		go_to_pos(rl->csr.pos, rl->cpypste.mkrs[1], rl);
		rl->cpypste.cpyed = TRUE;
		ft_strdel(&rl->cpypste.dat);
		rl->cpypste.dat = cpy;
	}
	return (kKeyOK);
}

/*
** Paste Selection (Shift + Down)
*/

t_keyact	rl_paste_key(t_readline *rl)
{
	if (!rl || !rl->cpypste.dat)
		return (kKeyFail);
	ft_bzero(&rl->cpypste.mkrs, sizeof(rl->cpypste.mkrs));
	rl->cpypste.idx = 0;
	rl->cpypste.cpyed = FALSE;
	if (!rl_line_add(rl->cpypste.dat, rl))
		return (kKeyFatal);
	return (kKeyOK);
}
