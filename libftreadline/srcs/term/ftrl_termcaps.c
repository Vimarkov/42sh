/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_termcaps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:20:20 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/15 14:12:40 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftrl_internal.h"

extern int		g_termcaps_fd;
int				g_termcaps_fd = TERMCAPS_DFL_FD;

int				putcf(int c)
{
	return ((int)write(g_termcaps_fd, &c, 1));
}

int				outcap_fd(char *name, int fd)
{
	int		bak;
	int		ret;

	bak = g_termcaps_fd;
	g_termcaps_fd = fd;
	ret = outcap(name);
	g_termcaps_fd = bak;
	return (ret);
}

int				outcap(char *name)
{
	char	*cap;

	cap = tgetstr(name, NULL);
	if (!cap || tputs(cap, 1, &putcf) == -1)
		return (FALSE);
	return (TRUE);
}

int				outcapstr(char *cstr)
{
	if (tputs(cstr, 1, &putcf) == -1)
		return (FALSE);
	return (TRUE);
}

int				outcap_arg_fb(char *cstr, char *fb, int arg, int affcnt)
{
	char	*prog;

	if (cstr)
	{
		if ((prog = tgoto(cstr, arg, arg)))
			return ((tputs(prog, affcnt, &putcf) == -1) ? FALSE : TRUE);
	}
	while (arg--)
	{
		if (!outcapstr(fb))
			return (FALSE);
	}
	return (TRUE);
}
