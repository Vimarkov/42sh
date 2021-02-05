/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:51:11 by kdumarai          #+#    #+#             */
/*   Updated: 2018/05/12 02:11:32 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_tabjoin(char **tab1, char **tab2)
{
	size_t	len1;
	size_t	len2;
	char	**ret;
	char	**brw;

	if (!tab1 || !tab2)
		return (NULL);
	len1 = ft_tablen(tab1);
	len2 = ft_tablen(tab2);
	if (!(brw = (char**)malloc(sizeof(char*) * (len1 + len2 + 1))))
		return (NULL);
	ret = brw;
	while (*tab1)
		*(brw++) = ft_strdup(*(tab1++));
	while (*tab2)
		*(brw++) = ft_strdup(*(tab2++));
	*brw = NULL;
	return (ret);
}
