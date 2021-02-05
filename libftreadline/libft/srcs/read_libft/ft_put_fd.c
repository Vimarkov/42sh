/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echojnow <echojnow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:46:57 by echojnow          #+#    #+#             */
/*   Updated: 2018/03/12 12:49:29 by echojnow         ###   ########.fr       */
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

static void	print_arg(va_list *va, const char *type, int fd)
{
	if (ft_strcmp(type, "d") == 0)
		ft_putnbr_fd(va_arg(*va, int), fd);
	else if (ft_strcmp(type, "ld") == 0)
		ft_putnbr_fd((int)va_arg(*va, size_t), fd);
	else if (ft_strcmp(type, "c") == 0)
		ft_putchar_fd((char)va_arg(*va, int), fd);
	else if (ft_strcmp(type, "s") == 0)
		ft_putstr_fd(va_arg(*va, char*), fd);
	else if (ft_strcmp(type, "%") == 0)
		ft_putchar_fd('%', fd);
}

void		ft_put_fd(int fd, const char *s, ...)
{
	va_list	va;
	int		i;
	char	*type;

	va_start(va, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] != '%')
			ft_putchar_fd(s[i], fd);
		else
		{
			type = isolate_type(&(s[i + 1]));
			print_arg(&va, type, fd);
			i += ft_strlenp(type);
			free(type);
		}
	}
	va_end(va);
}
