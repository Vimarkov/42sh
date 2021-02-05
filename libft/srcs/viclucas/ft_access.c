/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:49:53 by viclucas          #+#    #+#             */
/*   Updated: 2018/07/12 18:47:25 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int		ft_access_redir(char *s)
{
	struct stat		buf;

	lstat(s, &buf);
	if (access(s, F_OK) == -1)
		return (ft_error("42sh: no such file or directory: ", s));
	else if (access(s, X_OK) == -1)
	{
		lstat(s, &buf);
		if (S_ISDIR(buf.st_mode) == 1)
			return (ft_error("42sh: is a directory: ", s));
		return (ft_error("42sh: permission denied: ", s));
	}
	if (S_ISDIR(buf.st_mode) == 1)
		return (ft_error("42sh: is a directory: ", s));
	return (0);
}

void	ft_echo(char **board)
{
	int i;

	i = 1;
	while (board[i])
	{
		ft_putstr(board[i]);
		if (ft_strequ(board[i + 1], ">") || ft_strequ(board[i + 1], ">>") ||
				ft_strequ(board[i + 1], ">&"))
		{
			ft_putchar('\n');
			break ;
		}
		if (board[i + 1])
			ft_putchar(' ');
		else if (!board[i + 1])
			ft_putchar('\n');
		i++;
	}
}

int		ft_error(char *s1, char *name)
{
	if (!s1)
		return (-1);
	ft_putstr_fd(s1, 2);
	if (name)
		ft_putstr_fd(name, 2);
	ft_putchar_fd('\n', 2);
	return (-1);
}

char	*ft_acces(char *s)
{
	struct stat		buf;

	lstat(s, &buf);
	if (access(s, F_OK) == -1)
		return ("cd: no such file or directory: ");
	else if (access(s, X_OK) == -1)
	{
		lstat(s, &buf);
		if (S_ISDIR(buf.st_mode) != 1)
			return ("cd: not a directory: ");
		return ("cd: permission denied: ");
	}
	return (NULL);
}
