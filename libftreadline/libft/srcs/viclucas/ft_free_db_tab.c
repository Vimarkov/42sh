/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_db_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:41:17 by viclucas          #+#    #+#             */
/*   Updated: 2018/06/18 19:16:47 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_free_db_tab(char **av)
{
	int i;

	i = 0;
	if (!av)
		return (NULL);
	while (av[i])
		ft_strdel(&av[i++]);
	free(av);
	av = NULL;
	return (av);
}
