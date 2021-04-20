/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 19:24:43 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int			g_fd;
int			ft_printf(const char *str, ...);
int			fd_printf(int fd, const char *str, ...);
int			ft_check_conver(va_list ptr, int flag, int width, char **str1);
ssize_t		ft_write_int(va_list ptr, int flag, int width, int prec);
ssize_t		ft_write_char(va_list ptr, int flag, int width, char ch);
ssize_t		ft_write_str(va_list ptr, int flag, int width, int prec);
ssize_t		ft_write_un_int(va_list ptr, int flag, int width, int prec);
ssize_t		ft_write_x_lit(va_list ptr, int flag, int width, int prec);
ssize_t		ft_write_x_big(va_list ptr, int flag, int width, int prec);
char		*ft_turn_to_x(unsigned int n, int x);
char		*ft_un_itoa(unsigned int n);
ssize_t		ft_write_p(va_list ptr, int flag, int width, int prec);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
char		*ft_itoa(int n);
char		*ft_strjoin_char(char const *s1, char const c);
char		*ft_strdup1(const char *str);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *str);
int			ft_isdigit(int ch);

#endif
