/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:24:00 by echojnow          #+#    #+#             */
/*   Updated: 2018/02/28 14:32:16 by echojnow         ###   ########.fr       */
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

static void	print_arg(va_list *va, const char *type)
{
	if (ft_strcmp(type, "d") == 0)
		ft_putnbr(va_arg(*va, int));
	else if (ft_strcmp(type, "ld") == 0)
		ft_putnbr((int)va_arg(*va, size_t));
	else if (ft_strcmp(type, "c") == 0)
		ft_putchar((char)va_arg(*va, int));
	else if (ft_strcmp(type, "s") == 0)
		ft_putstr(va_arg(*va, char*));
	else if (ft_strcmp(type, "%") == 0)
		ft_putchar('%');
}

void		ft_put(const char *s, ...)
{
	va_list	va;
	int		i;
	char	*type;

	va_start(va, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] != '%')
			ft_putchar(s[i]);
		else
		{
			type = isolate_type(&(s[i + 1]));
			print_arg(&va, type);
			i += ft_strlenp(type);
			free(type);
		}
	}
	va_end(va);
}
