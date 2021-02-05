/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 02:01:46 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/08 18:42:23 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "ftrl_internal.h"

inline static void	set_keys_movs(t_keys *keys, t_mov *movs, t_uint8 dumb)
{
	char			**keysptr;
	unsigned int	idx;
	const char		*caps[8] = {"kl", "kr", "ku", "kd", "kh", "@7", "kD", "kE"};
	const char		*dfl[8] = {"\033[D", "\033[C", "\033[A", "\033[B",
							"\033[H", "\033[F", "\033[3~", "\025"};

	keysptr = (char**)keys;
	idx = 0;
	while (idx < sizeof(caps) / sizeof(caps[0]))
	{
		if (dumb
			|| !(keysptr[idx] = tgetstr((char*)((t_uintptr)caps[idx]), NULL)))
			keysptr[idx] = (char*)(t_uintptr)dfl[idx];
		idx++;
	}
	movs->leftm = tgetstr("le", NULL);
	movs->rightm = tgetstr("nd", NULL);
	movs->upm = tgetstr("up", NULL);
	movs->downm = tgetstr("do", NULL);
	movs->cecap = tgetstr("ce", NULL);
	movs->crcap = tgetstr("cr", NULL);
	movs->dlargcap = tgetstr("DL", NULL);
	movs->dlcap = tgetstr("dl", NULL);
}

void				rl_deinit(t_readline *rl)
{
	if (!rl_set_term(YES))
		return ;
	(void)outcap("ke");
	restore_signals();
	free(rl->prompt);
	ft_strdel(&rl->cpypste.dat);
	if (rl->heap_opts)
		free(rl->opts);
}

inline static void	rl_makesure_start(const char *termenv, t_uint8 dumb)
{
	char	rbuff[10];
	char	*tmp;

	if (dumb || (!ft_strequ(termenv, "xterm")
		&& !ft_strequ(termenv, "xterm-color")
		&& !ft_strequ(termenv, "xterm-256color")))
	{
		ft_putchar_fd('\n', STDIN_FILENO);
		return ;
	}
	if (!rl_set_timeout(YES, 0))
		return ;
	while (TRUE)
		if (read(STDIN_FILENO, rbuff, sizeof(rbuff)) < 1)
			break ;
	(void)rl_set_timeout(NO, 0);
	ft_putstr_fd("\033[6n", STDIN_FILENO);
	bzero(rbuff, sizeof(rbuff));
	if (read(STDIN_FILENO, rbuff, 8) < 1)
		return ;
	if (!(tmp = ft_strrchr(rbuff, ';')) || ft_atoi(tmp + 1) < 2)
		return ;
	(void)outcap("mr");
	ft_putstr_fd("%\n", STDIN_FILENO);
	(void)outcap("me");
}

static t_rl_opts	*get_opts(t_rl_opts *user_opts, t_readline *rl)
{
	t_rl_opts	*ret;

	if (user_opts)
		return (user_opts);
	if (!(ret = (t_rl_opts*)ft_memalloc(sizeof(t_rl_opts))))
		return (NULL);
	rl->heap_opts = TRUE;
	ret->tbell = TRUE;
	ret->dumb_prompt = TRUE;
	return (ret);
}

t_uint8				rl_init(t_readline *rl, const char *prompt, t_rl_opts *opts)
{
	char		*termenv;

	ft_bzero(rl, sizeof(t_readline));
	if (!(termenv = getenv("TERM")))
	{
		rl->dumb = TRUE;
		termenv = "dumb";
	}
	rl->opts = get_opts(opts, rl);
	rl->origpr = prompt;
	if (!rl->opts || !rl_linebuff_create(rl) || !tgetent(NULL, termenv)
		|| !rl_prompt_init(&rl->prompt, &rl->prlen, rl))
		return (FALSE);
	set_keys_movs(&rl->keys, &rl->movs, rl->dumb);
	if (!rl_set_term(NO))
		return (FALSE);
	(void)rl_latest_session(YES, rl);
	rl_makesure_start(termenv, rl->dumb);
	set_signals();
	(void)outcap("ks");
	rl->ret = FTRL_OK;
	return (TRUE);
}
