/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_soudeur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:03:55 by viclucas          #+#    #+#             */
/*   Updated: 2018/07/07 04:07:54 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
