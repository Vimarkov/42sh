/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:45:50 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/15 14:35:13 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftrl_internal.h"

static void		print_end_newlines(t_readline *rl)
{
	t_point			coords;
	t_point			maxc;
	size_t			times;
	char			*nlb;

	if (!rl || !rl->line)
	{
		ft_putchar_fd('\n', STDIN_FILENO);
		return ;
	}
	get_line_info(&coords, rl);
	get_line_info_for_pos(&maxc, rl->csr.max, rl);
	times = maxc.y - coords.y + 1;
	if (!(nlb = (char*)malloc(sizeof(char) * (times + 1))))
		return ;
	(void)ft_memset(nlb, '\n', times);
	nlb[times] = '\0';
	ft_putstr_fd(nlb, STDIN_FILENO);
	free(nlb);
}

static t_keyact	nav_keys(char *buff, t_readline *rl)
{
	t_keyact		status;
	unsigned short	idx;
	static t_keyact	(*f[])(t_readline*) =
	{&rl_leftcpy_key, &rl_rightcpy_key, &rl_cpy_key, &rl_paste_key,
	&rl_right_key, &rl_left_key, &rl_home_key, &rl_end_key, &rl_movl_key,
	&rl_movr_key, &rl_moveline_up, &rl_moveline_down, NULL};
	const char		*keys[] = {ESC_SHIFTL, ESC_SHIFTR, ESC_SHIFTU,
	ESC_SHIFTD, rl->keys.rightk, rl->keys.leftk, rl->keys.homek,
	rl->keys.endk, ESC_MOVL, ESC_MOVR, ESC_ALTU, ESC_ALTD, NULL};

	if (!rl || !buff)
		return (kKeyFail);
	idx = 0;
	while (f[idx] && keys[idx])
	{
		if (ft_strequ(keys[idx], buff))
		{
			(idx > 3) ? check_selection(rl) : (void)0;
			if ((status = f[idx](rl)) != kKeyNone)
				return (status);
		}
		idx++;
	}
	return (kKeyNone);
}

static t_keyact	edit_keys(char *buff, t_readline *rl)
{
	t_keyact	tmp;

	if (!rl || !buff)
		return (kKeyNone);
	if (*buff == 3)
	{
		ft_strdel(&rl->line);
		rl->ret = FTRL_SIGINT;
		return (kKeyOK);
	}
	if (*buff == 4)
		return (rl_eof_key(rl));
	if (ft_strequ(buff, "\025"))
		return (rl_clear_line(rl));
	if (ft_strequ(buff, "\t"))
		return (rl_acroutine(rl));
	if (ft_strequ(ESC_CTRLL, buff))
		return (rl_clscr_key(rl));
	if ((tmp = rl_input_rm_text(buff, rl)) != kKeyNone)
		return (tmp);
	if ((tmp = rl_input_add_text(buff, rl)) != kKeyNone)
		return (tmp);
	return (kKeyNone);
}

static int		ft_readline_core(t_readline *rl, t_dlist **hist)
{
	t_keyact		status;
	char			buff[RL_READBUFFSIZE + 1];

	ft_putstr_fd(rl->prompt, rl->opts->outfd);
	ft_putstr_fd(rl->line, STDIN_FILENO);
	go_to_pos(rl->csr.pos, rl->csr.max, rl);
	while (rl->line && rl->quit.reason == kAbortNone)
	{
		ft_bzero(buff, sizeof(buff));
		if (read(STDIN_FILENO, buff, RL_READBUFFSIZE) < 1
			|| ft_strequ(buff, "\n"))
			break ;
		if (((status = nav_keys(buff, rl)) < kKeyFail
			&& (status = hist_nav(buff, rl, hist)) < kKeyFail
			&& (status = edit_keys(buff, rl)) < kKeyFail))
			continue ;
		if (status == kKeyFail && rl->opts->tbell && !rl->dumb)
			(void)outcap("bl");
		if (status == kKeyFatal)
			return (FTRL_FAIL);
	}
	return (rl->ret);
}

int				ft_readline(char **line, const char *prompt,
							t_rl_opts *opts, t_dlist *hist)
{
	t_readline		rl;
	t_readline		*bak;

	if ((bak = rl_latest_session(NO, NULL)) || !rl_init(&rl, prompt, opts))
		return (FTRL_FAIL);
	while (rl.line)
	{
		rl.ret = ft_readline_core(&rl, &hist);
		check_selection(&rl);
		(rl.quit.reason != kAbortClear) ? print_end_newlines(&rl) : (void)0;
		if (rl.quit.reason < kAbortReload)
			break ;
		if (rl.quit.func)
		{
			(rl.quit.func)(rl.quit.func_data);
			(rl.quit.free_func)(rl.quit.func_data);
		}
		if (rl.quit.reason == kAbortReload && !rl_set_timeout(NO, 0))
			break ;
		ft_bzero(&rl.quit, sizeof(t_quit));
	}
	rl_deinit(&rl);
	(void)rl_latest_session(YES, bak);
	*line = rl.line;
	return (rl.ret);
}
