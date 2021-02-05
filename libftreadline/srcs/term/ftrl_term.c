/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 02:01:46 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/08 19:22:53 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "ftrl_internal.h"

void		tcaps_set_extern(struct termios *pterm)
{
	struct termios	t;
	char			*pcstr;

	if (!pterm)
	{
		if (tcgetattr(STDIN_FILENO, &t) == -1)
			return ;
		pterm = &t;
	}
	ospeed = (short)pterm->c_ospeed;
	pcstr = tgetstr("pc", NULL);
	PC = (pcstr) ? *pcstr : 0;
}

int			rl_set_term(t_uint8 echo)
{
	static struct termios	saved_t;
	struct termios			t;
	static t_uint8			state = 0;

	if (state != echo || (!echo && tcgetattr(STDIN_FILENO, &saved_t) == -1))
		return (FALSE);
	tcaps_set_extern(&saved_t);
	if (!echo)
	{
		t = saved_t;
		t.c_lflag &= (unsigned long)~(ICANON | ECHO | ISIG);
		(void)tcsetattr(STDIN_FILENO, TCSANOW, &t);
		state = 1;
	}
	else
	{
		(void)tcsetattr(STDIN_FILENO, TCSANOW, &saved_t);
		state = 0;
	}
	return (TRUE);
}

t_uint8		rl_set_timeout(t_uint8 enable, cc_t timeout)
{
	struct termios		t;

	if (tcgetattr(STDIN_FILENO, &t) == -1)
		return (FALSE);
	t.c_cc[VMIN] = !enable;
	t.c_cc[VTIME] = timeout;
	return (tcsetattr(STDIN_FILENO, TCSANOW, &t) != -1);
}
