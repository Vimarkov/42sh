/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 22:36:06 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/28 18:12:34 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "libft.h"

void	ft_putchar(char c);
void	ft_putnchar(char c, size_t n);
void	ft_putstr(char const *s);
void	ft_putstrsec(char const *s);
void	ft_putendl(char const *s);
void	ft_putendlsec(char const *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putnchar_fd(char c, size_t n, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstrsec_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putendlsec_fd(char const *s, int fd);

size_t	ft_putstrmax(const char *s, size_t len);
size_t	ft_putstrmax_fd(const char *s, size_t len, int fd);
size_t	ft_putendlmax(const char *s, size_t len);
size_t	ft_putendlmax_fd(const char *s, size_t len, int fd);

void	ft_putstr_color(char const *s, char const *ec);
void	ft_putstr_color_fd(char const *s, char const *ec, int fd);
void	ft_putendl_color(char const *s, char const *ec);
void	ft_putendl_color_fd(char const *s, char const *ec, int fd);

void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbrl(int n);
void	ft_putnbrl_fd(int n, int fd);

void	ft_putnbr_ll_fd(long long n, int fd);
void	ft_putnbr_ll(long long n);

void	ft_putlst(t_list *lst);
void	ft_putlst_fd(t_list *lst, int fd);

void	ft_putubt(t_btree *bt, void (*ft_putelem)(void*, size_t));

#endif
