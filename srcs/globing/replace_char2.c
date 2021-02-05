/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:18:29 by viclucas          #+#    #+#             */
/*   Updated: 2018/08/16 04:44:10 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_globing.h"

char			*get_prev_string(char *surface)
{
	int					o;
	char				*prev;

	o = 0;
	if (ft_strchr(surface, '/') == NULL)
		return (NULL);
	while (surface[o] && surface[o] != '?' && surface[o] != '[' &&
			surface[o] != '*')
		o++;
	while (o > 0 && surface[o] != '/')
		o--;
	if (surface[o] == '/' && o > 0)
		o--;
	if (o == 0)
		return (NULL);
	prev = ft_strndup(surface, o + 1);
	return (prev);
}
