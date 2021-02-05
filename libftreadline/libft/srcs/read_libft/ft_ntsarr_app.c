/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntsarr_app.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:23:11 by echojnow          #+#    #+#             */
/*   Updated: 2018/05/12 13:37:49 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_libft.h"

char	**ft_ntsarr_app(char ***ntsarr, char *s)
{
	size_t	len;
	char	**new;
	int		i;

	if (!ntsarr)
		return (NULL);
	len = ft_ntsarr_len(*ntsarr);
	if ((new = (char**)malloc(sizeof(char*) * (len + 2))) == NULL)
		return (NULL);
	new[len + 1] = NULL;
	new[len] = s;
	if (len > 0)
	{
		i = -1;
		while (++i < (int)len)
			new[i] = (*ntsarr)[i];
	}
	free(*ntsarr);
	*ntsarr = new;
	return (&new[len]);
}
