NAME = 21sh

MAIN =	main.c

BUILTINS =	bltn_cd.c bltn_echo.c bltn_exit.c bltn_setenv.c bltn_pwd.c bltn_unset.c

ENV =	assemble_env.c get_env_var.c parse_env_var.c update_env.c \
        create_env_instance.c init_env.c print_env.c

PARSE = assemble_tokens_to_cmds.c	parse_token.c \
		check_redir.c				push.c \
		parse_quotes.c				validation.c \
		parse_utils.c               multiline_cmd.c \
		aggro.c

UTILS =	two_d_array.c           ft_isspace.c            ft_split.c              ft_strjoin_tripple.c    init.c \
		errors.c                ft_itoa.c               ft_strcmp.c             ft_strlen_shell.c       show_promt.c \
        free.c                  ft_malloc.c             ft_strdup.c             get_next_line.c         signals.c \
        ft_is_sep_cmd.c         ft_skip_spaces.c        ft_strequ.c             get_next_line_utils.c	ft_is_export.c \
        is_number.c             starts_with.c           ft_strnstr.c

PATH =	get_path.c      path_utils.c

QUEUE =	join_queue.c    pop.c           pop_front.c     push_back.c

EXEC =	check_redirs.c  exec.c          exec_loop.c     aggreg.c

# VARIABLES FOR HEADERS

INCDIR		= 	./headers/

INCLUDES	=	minishell.h structs.h get_next_line.h

HEADERS		=	$(addprefix $(INCDIR),$(INCLUDES))


# VARIABLES FOR PFT

PFT			= ./ft_printf/
PFT_LIB		= $(addprefix $(PFT),libftprintf.a)
PFT_INC		= -L ./ft_printf -l ftprintf

# DEPS

DEPS		= 	$(HEADERS) Makefile

# COMPILING FLAGS

CC			= gcc -O2
CFLAGS		= -Wall -Wextra -Werror

# VARIABLES FOR .C DIRECTORIES

SRCDIR		= ./srcs/
PARSEDIR	= $(SRCDIR)parsing/
UTILDIR		= $(SRCDIR)utils/
MAINDIR		= $(SRCDIR)main/
ENVDIR		= $(SRCDIR)env/
BUILTINSDIR	= $(SRCDIR)builtins/
PATHDIR		= $(SRCDIR)path/
QUEUEDIR	= $(SRCDIR)queue/
EXECDIR		= $(SRCDIR)exec/

# LIST VARIABLES FOR  *.c files


PARSESRC	= $(addprefix $(PARSEDIR),$(PARSE))
UTILSRC		= $(addprefix $(UTILDIR),$(UTILS))
MAINSRC		= $(addprefix $(MAINDIR),$(MAIN))
ENVSRC		= $(addprefix $(ENVDIR),$(ENV))
BUILTINSRC	= $(addprefix $(BUILTINSDIR),$(BUILTINS))
PATHSRC		= $(addprefix $(PATHDIR),$(PATH))
QUEUESRC	= $(addprefix $(QUEUEDIR),$(QUEUE))
EXECSRC		= $(addprefix $(EXECDIR),$(EXEC))

# LIST VARIABLES FOR MANDATORY PART *.c FILES

SRCS		+= $(PARSESRC) $(MAINSRC) $(UTILSRC) $(ENVSRC) $(BUILTINSRC) $(PATHSRC) $(QUEUESRC) $(EXECSRC)

# LIST VARIABLES FOR MANDATORY OBJECT FILES

OBJDIR		= ./objs/
OBJS		= $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)


#-----------------

.PHONY:			all clean fclean re LIB_RELINK

all: $(NAME)

$(NAME): $(OBJS) $(PFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(PFT_INC) -o $(NAME)

$(PFT_LIB): LIB_RELINK
	make -C ft_printf/

$(OBJDIR)%.o : $(SRCDIR)%.c $(DEPS)
	mkdir -p $(OBJDIR) $(OBJDIR)parsing $(OBJDIR)main $(OBJDIR)utils $(OBJDIR)env $(OBJDIR)builtins $(OBJDIR)path $(OBJDIR)queue $(OBJDIR)exec
	$(CC) $(CFLAGS) -MD -I $(INCDIR) $< -c -o $@

clean:
	/bin/rm -rf $(OBJDIR)
	make -C ft_printf/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ft_printf/ fclean

re: fclean all
