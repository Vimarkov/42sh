/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_historykeys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:06:01 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/15 22:41:37 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftrl_internal.h"

static t_dlist	*get_new_line(t_dlist *lst, t_direct mode)
{
	t_dlist	*tmp;

	tmp = lst;
	while ((mode == kDirectLeft) ? tmp->prev : tmp->next)
	{
		tmp = (mode == kDirectLeft) ? tmp->prev : tmp->next;
		if (!tmp->content || !ft_strchr((char*)tmp->content, '\n'))
			break ;
	}
	return ((tmp->content && ft_strchr(tmp->content, '\n')) ? lst : tmp);
}

static t_keyact	rl_history_keys(char *buff, t_readline *rl, t_dlist **history)
{
	int		keys[2];
	t_dlist	*tmp;

	keys[0] = (ft_strequ(buff, rl->keys.upk));
	keys[1] = (ft_strequ(buff, rl->keys.downk));
	if (!keys[0] && !keys[1])
		return (kKeyNone);
	if (!history || !*history)
		return (kKeyFail);
	tmp = *history;
	if (keys[0] && tmp->next)
		tmp = rl->dumb ? get_new_line(*history, kDirectRight) : tmp->next;
	else if (keys[1] && tmp->prev)
		tmp = rl->dumb ? get_new_line(*history, kDirectLeft) : tmp->prev;
	else
		return (kKeyFail);
	*history = tmp;
	return (kKeyOK);
}

static void		disp_new_line_dumb(t_point *maxc, t_readline *rl)
{
	if (maxc->y == 1)
	{
		ft_putchar('\r');
		ft_putnchar_fd(' ', g_ws.ws_col, STDIN_FILENO);
		ft_putchar_fd('\r', STDIN_FILENO);
		ft_putstr_fd(rl->prompt, STDIN_FILENO);
		(void)ft_putstrmax_fd(rl->line,
							g_ws.ws_col - rl->prlen - 2, STDIN_FILENO);
	}
	else
		go_to_pos(rl->csr.max, 0, rl);
}

static void		disp_new_line(t_point *maxc, t_readline *rl)
{
	const char *tmp = rl->line;
	const char *chr;

	if (rl->dumb)
	{
		disp_new_line_dumb(maxc, rl);
		return ;
	}
	(void)outcapstr(rl->movs.crcap);
	(void)outcap_arg_fb(rl->movs.dlargcap, rl->movs.dlcap,
						(int)maxc->y, (int)maxc->y);
	ft_putstr_fd(rl->prompt, rl->opts->outfd);
	ft_putstr_fd(rl->line, STDIN_FILENO);
	while ((chr = ft_strchr(tmp, '\n')))
		tmp = chr + 1;
	if (ft_strlen(tmp) + rl->prlen == g_ws.ws_col)
	{
		ft_putchar_fd(' ', STDIN_FILENO);
		(void)outcapstr(rl->movs.leftm);
	}
}

t_keyact		hist_nav(char *buff, t_readline *rl, t_dlist **hist)
{
	t_point		maxc;
	t_keyact	retk;

	if ((retk = rl_history_keys(buff, rl, hist)) != kKeyOK)
		return (retk);
	get_line_info_for_pos(&maxc, rl->csr.max, rl);
	go_to_pos(0, rl->csr.pos, rl);
	free(rl->line);
	if ((char*)(*hist)->content)
	{
		rl->line = ft_strdup((char*)(*hist)->content);
		rl->bufflen = ft_strlen(rl->line);
	}
	else if (!rl_linebuff_create(rl))
		return (kKeyFatal);
	rl->csr.max = ft_strlen(rl->line);
	rl->csr.pos = rl->csr.max;
	disp_new_line(&maxc, rl);
	return (kKeyOK);
}
