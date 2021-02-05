/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimarkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:49:03 by vimarkov          #+#    #+#             */
/*   Updated: 2018/08/10 00:36:03 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_globing.h"

int		nb_blank(char *name, char **known, int o, int i)
{
	while (name[i])
	{
		if (ft_strnequ(name + i, known[o], ft_strlen(known[o])))
		{
			if (name[i + ft_strlen(known[o])] == '\0')
			{
				return (i);
			}
		}
		i++;
	}
	return (0);
}
