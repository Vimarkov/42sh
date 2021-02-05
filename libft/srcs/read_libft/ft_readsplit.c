/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:39:01 by echojnow          #+#    #+#             */
/*   Updated: 2018/01/05 12:18:45 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_libft.h"

static int	first_nonblank(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	return (i);
}

static int	last_nonblank(char *s)
{
	int	i;

	i = ft_strlenp(s) - 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i--;
	return (i + 1);
}

char		**ft_readsplit(char *s, char c, int dont_escape)
{
	char	**t;
	char	**current_line;
	int		last;
	int		i;
	int		in_esc;

	t = ft_ntsarr_new();
	current_line = ft_ntsarr_app(&t, ft_strnew(0));
	last = last_nonblank(s);
	i = first_nonblank(s) - 1;
	in_esc = 0;
	while (++i < last)
	{
		if (!in_esc && s[i] == c)
			current_line = ft_ntsarr_app(&t, ft_strnew(0));
		else if (!in_esc && s[i] == '\\' && !dont_escape)
			in_esc = 1;
		else if (!in_esc || (in_esc && ((in_esc = 0) == 0)))
			*current_line = ft_strappcf(*current_line, s[i]);
	}
	return (t);
}
