/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_read_bltncmd2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 23:35:25 by echojnow          #+#    #+#             */
/*   Updated: 2018/07/27 00:04:50 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*get_line(t_rl_opts *opts, int nl_escaped)
{
	char		*line;
	char		*final;
	char		*escaped_line;

	line = NULL;
	final = NULL;
	ft_readline(&line, nl_escaped > 0 ? "> " : NULL, opts, NULL);
	if (!line)
		return (NULL);
	if (nl_escaped > -1 && line[ft_strlenp(line) - 1] == '\\')
	{
		escaped_line = get_line(opts, 1);
		final = ft_strapp(line, escaped_line);
		free(escaped_line);
		free(line);
	}
	else
		return (line);
	return (final);
}

char		**argv_pop(int argc, char **argv, int pops)
{
	char	**new;
	int		i;
	int		j;

	new = (char**)malloc(sizeof(char*) * (argc - pops + 1));
	new[argc - pops] = NULL;
	i = pops;
	j = 0;
	while (i < argc)
	{
		new[j] = argv[i];
		i++;
		j++;
	}
	return (new);
}
