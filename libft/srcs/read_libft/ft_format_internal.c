/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_internal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 11:28:28 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/12 13:59:08 by echojnow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_libft.h"

static char	*isolate_type(const char *s)
{
	int		i;

	i = 0;
	while (s[i] == 'd' || s[i] == 'l' || s[i] == 'c' || s[i] == 's'
			|| (s[i] == '%' && i == 0))
		i++;
	return (ft_strsub(s, 0, i));
}

static int	print_arg(va_list *va, const char *type, char **fs)
{
	char *s;

	s = NULL;
	if (ft_strcmp(type, "d") == 0)
	{
		if (((s = ft_itoa((int)va_arg(*va, size_t))) == NULL)
				|| ((*fs = ft_strappf(*fs, s)) == NULL))
			return (1);
	}
	else if (ft_strcmp(type, "c") == 0)
	{
		if ((*fs = ft_strappcf(*fs, (char)va_arg(*va, int))) == NULL)
			return (1);
	}
	else if (ft_strcmp(type, "s") == 0)
	{
		if (((s = ft_strdup(va_arg(*va, char*))) == NULL)
				|| ((*fs = ft_strappf(*fs, s)) == NULL))
			return (1);
	}
	else if (ft_strcmp(type, "%") == 0)
		if ((*fs = ft_strappcf(*fs, '%')) == NULL)
			return (1);
	return (0);
}

static int	make_fs(char **fs, const char *s, va_list *va)
{
	int		i;
	char	*type;

	i = -1;
	while (s[++i])
	{
		if (s[i] != '%')
		{
			if ((*fs = ft_strappcf(*fs, s[i])) == NULL)
				return (1);
		}
		else
		{
			if (((type = isolate_type(&(s[i + 1]))) == NULL)
					|| ((print_arg(va, type, fs)) == 1))
				return (1);
			i += ft_strlenp(type);
			free(type);
		}
	}
	return (0);
}

char		*ft_format_internal(const char *s, va_list *va)
{
	char	*fs;
	va_list	vac;

	if ((fs = ft_strnew(1)) == NULL)
		return (NULL);
	va_copy(vac, *va);
	if (make_fs(&fs, s, &vac) == 1)
		return (NULL);
	va_end(vac);
	return (fs);
}
