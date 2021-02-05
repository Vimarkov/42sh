/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_thoses.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:33:42 by viclucas          #+#    #+#             */
/*   Updated: 2018/06/08 19:43:05 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_thoses(char **s1, char **s2, char **s3, char **s4)
{
	if (s1 != NULL)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 != NULL)
	{
		free(*s2);
		*s2 = NULL;
	}
	if (s3 != NULL)
	{
		free(*s3);
		*s3 = NULL;
	}
	if (s4 != NULL)
	{
		free(*s4);
		*s4 = NULL;
	}
}
