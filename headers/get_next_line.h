/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:19:49 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 22:20:40 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
