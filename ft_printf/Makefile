# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: airma <airma@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/31 13:18:00 by airma             #+#    #+#              #
#    Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_strdup.c ft_strlen.c  ft_itoa.c  ft_charjoin.c  from_libft.c \
       ft_write_char.c ft_write_int.c ft_write_x.c  ft_printf.c \
	   ft_write_str.c  ft_write_un_int.c ft_write_p.c  \
	   ft_check_conver.c  ft_turn_to_x.c ft_un_itoa.c

CC	= gcc -O3
OBJ = $(SRCS:.c=.o)

INCLUDES= ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	/usr/bin/ar rc $(NAME) $(OBJ)
	/usr/bin/ranlib $(NAME)

%.o: %.c $(INCLUDES)
	/usr/bin/gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
