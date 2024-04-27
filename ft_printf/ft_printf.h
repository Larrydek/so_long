/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:49:50 by jde-clee          #+#    #+#             */
/*   Updated: 2023/10/03 20:50:52 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *type, ...);
void	ft_format(char const *type, va_list args, int *len);
void	ft_hex_len(unsigned int n, int *len);
size_t	ft_int_len(int n);
void	ft_putnbr(int n);
void	ft_char(char c, int *len);
void	ft_string(char *s, int *len);
void	ft_float(int n, int *len);
void	ft_hex(unsigned int n, const char format, int *len);
int		*ft_print_hex(unsigned int nbr, const char format, int *len);
void	ft_void(unsigned long int n, int *len);
int		*ft_print_void(unsigned long int ptr, int *len);
void	ft_putnbr(int n);
int		*ft_print_num(int num, int *len);
void	ft_unsigned(unsigned int n, int *len);
int		*ft_print_uint(unsigned int num, int *len);

#endif
