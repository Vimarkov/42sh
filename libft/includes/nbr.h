/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 22:36:06 by kdumarai          #+#    #+#             */
/*   Updated: 2018/06/01 01:46:09 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NBR_H
# define NBR_H

# include <string.h>

void	ft_nbrcpy(char *dst, long nb);
void	ft_nbrcat(char *dst, long nb);
size_t	ft_nbrlen_base(long long n, int base);
size_t	ft_nbrlen(long long n);
int		ft_atoi(const char *str);
int		ft_secatoi(int *dest, const char *str);
char	*ft_itoa(int n);
char	*ft_lltoa(long long nl);

#endif
