/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_export_bltncmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 05:55:10 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/16 06:13:17 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "sh.h"

static int	export_usage(char a)
{
	ft_putstr_fd("export: illegal option -- ", STDERR_FILENO);
	ft_putchar_fd(a, STDERR_FILENO);
	ft_putendl_fd("\nusage: [name[=value] ...] or export -p", STDERR_FILENO);
	return (EXIT_FAILURE);
}

static void	print_vars(void)
{
	extern char	**environ;
	char		**bw;

	bw = environ;
	while (*bw)
	{
		ft_putstr("export ");
		ft_putendl(*(bw++));
	}
}

int			export_bltn(int ac, char **av)
{
	int		idx;
	int		export_opts;
	int		exval;

	idx = 1;
	if ((export_opts = ft_args_opts(av, &idx, "p", NULL)) < 0)
		return (export_usage((char)-export_opts));
	if (idx == 1 || ((export_opts & 0x1) && !av[idx]))
	{
		print_vars();
		return (EXIT_SUCCESS);
	}
	exval = EXIT_SUCCESS;
	while (ac > 1 && av[idx])
	{
		if (!ft_strchr(av[idx], '='))
			break ;
		if (!set_env_from_str(NULL, av[idx]))
			exval = EXIT_FAILURE;
		idx++;
	}
	return (exval);
}
