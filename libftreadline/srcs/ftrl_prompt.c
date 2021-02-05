/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 03:45:43 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/05 04:31:57 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftrl_internal.h"

inline static t_uint8	ftrl_prompt_isvalid_dumb_core(struct winsize *ptr,
													size_t prlen)
{
	struct winsize	ws;

	if (!ptr)
	{
		if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) == -1)
			return (FALSE);
		ptr = &ws;
	}
	return ((prlen <= ptr->ws_col * 3 / 4));
}

t_uint8					ftrl_prompt_isvalid_dumb(const char *prompt)
{
	return (ftrl_prompt_isvalid_dumb_core(NULL, ft_prompt_len(prompt)));
}

t_uint8					rl_prompt_init(char **dest, size_t *len, t_readline *rl)
{
	if (!dest || !len)
		return (FALSE);
	*len = (rl->origpr == NULL) ? 0 : ft_prompt_len(rl->origpr);
	if (!rl->dumb || rl->opts->dumb_prompt)
	{
		if (rl->dumb || tgetnum("Co") < 8)
			*dest = ft_prompt_nocolor(rl->origpr);
		else
			*dest = ft_strdup((rl->origpr == NULL) ? "" : rl->origpr);
	}
	if (rl->dumb && (!rl->opts->dumb_prompt
					|| !ftrl_prompt_isvalid_dumb_core(NULL, *len)))
	{
		free(*dest);
		*dest = ft_strdup(DFL_DUMB_PR);
		*len = ft_strlen(rl->prompt);
	}
	return (*dest != NULL);
}

inline void				rl_show_prompt(t_readline *rl)
{
	ft_putstr_fd(rl->prompt, rl->opts->outfd);
}
