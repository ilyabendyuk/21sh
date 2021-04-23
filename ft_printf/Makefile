SRC	= 	ft_printf.c \
		ft_strcmp.c \
		gets.c \
		prints.c \
		processing.c \
		puts.c \
		ft_atoi.c

OBJ =	$(SRC:.c=.o)	

SRCDIR	= src
OBJDIR	= obj
SRCS	= $(addprefix $(SRCDIR)/, $(SRC))
OBJS	= $(addprefix $(OBJDIR)/, $(OBJ))

NAME	= libftprintf.a

.PHONY:		all clean fclean re

all: $(NAME)

INCDIR = ./includes/

INCLUDES =	ft_pft.h\
			ft_printf.h

HEADERS		=	$(addprefix $(INCDIR),$(INCLUDES))

DEPS		= 	$(HEADERS) Makefile

$(NAME): $(OBJDIR) $(OBJS)
	/usr/bin/ar rc $(NAME) $(OBJS)
	/usr/bin/ranlib $(NAME)

$(OBJDIR):
	/bin/mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	/usr/bin/gcc -c -MD -I $(INCDIR) -Wall -Wextra -Werror $< -o $@

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
