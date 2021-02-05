/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:21:00 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/08 19:06:39 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "ftrl_internal.h"

static void	(*g_sig_origs[32])(int);

static void	rl_generic_sig_hdl(int sigc)
{
	t_readline	*session;

	if (g_sig_origs[sigc] == SIG_ERR
		|| g_sig_origs[sigc] == SIG_IGN
		|| !(session = rl_latest_session(NO, NULL)))
		return ;
	if (g_sig_origs[sigc] == SIG_DFL)
	{
		rl_deinit(session);
		ft_putchar('\n');
		if (signal(sigc, g_sig_origs[sigc]) != SIG_ERR)
			(void)raise(sigc);
		return ;
	}
	(g_sig_origs[sigc])(sigc);
}

static void	set_custom_winsize(void)
{
	struct winsize	cws;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &cws) == -1)
	{
		ft_bzero(&g_ws, sizeof(struct winsize));
		return ;
	}
	g_ws.ws_col = cws.ws_col;
	g_ws.ws_row = cws.ws_row;
}

static void	winsize_hdl(int sigc)
{
	t_readline		*session;
	char			*new_pr;
	size_t			new_len;

	if (sigc != SIGWINCH || !(session = rl_latest_session(NO, NULL)))
		return ;
	set_custom_winsize();
	if (session->dumb)
	{
		if (rl_prompt_init(&new_pr, &new_len, session))
		{
			free(session->prompt);
			session->prompt = new_pr;
			session->prlen = new_len;
		}
		ftrl_reload();
	}
	else
		session->prlen = ft_prompt_len(session->prompt);
}

void		set_signals(void)
{
	int		sig;

	sig = 0;
	while (++sig < 32)
	{
		if (sig == SIGURG || sig == SIGCONT || sig == SIGCHLD
			|| sig == SIGIO || sig == SIGWINCH)
			g_sig_origs[sig] = SIG_ERR;
		else
			g_sig_origs[sig] = signal(sig, &rl_generic_sig_hdl);
	}
	set_custom_winsize();
	g_sig_origs[SIGWINCH] = signal(SIGWINCH, &winsize_hdl);
}

void		restore_signals(void)
{
	int		sig;

	sig = 0;
	while (++sig < 32)
	{
		if (g_sig_origs[sig] == SIG_ERR)
			continue ;
		(void)signal(sig, g_sig_origs[sig]);
	}
}
