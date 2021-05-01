cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_C_STANDARD 99)

set(LIBRARY_PATH /Users/ilabenduk/Desktop/2121/ft_printf/libftprintf.a)

#LINK_DIRECTORIES(/res)
add_executable(untitled
        ft_printf/libftprintf.a
        srcs/builtins/bltn_cd.c
        srcs/builtins/bltn_echo.c
        srcs/builtins/bltn_exit.c
        srcs/builtins/bltn_setenv.c
        srcs/builtins/bltn_pwd.c
        srcs/builtins/bltn_unset.c
        srcs/env/assemble_env.c
        srcs/env/create_env_instance.c
        srcs/env/get_env_var.c
        srcs/env/init_env.c
        srcs/env/parse_env_var.c
        srcs/env/print_env.c
        srcs/env/update_env.c
        srcs/exec/check_redirs.c
        srcs/exec/exec.c
        srcs/exec/exec_loop.c
        srcs/main/main.c
        srcs/parsing/assemble_tokens_to_cmds.c
        srcs/parsing/check_redir.c
        srcs/parsing/parse_quotes.c
        srcs/parsing/parse_token.c
        srcs/parsing/push.c
        srcs/parsing/validation.c
        srcs/path/get_path.c
        srcs/path/path_utils.c
        srcs/queue/join_queue.c
        srcs/queue/pop.c
        srcs/queue/pop_front.c
        srcs/queue/push_back.c
        srcs/utils/errors.c
        srcs/utils/free.c
        srcs/utils/ft_is_sep_cmd.c
        srcs/utils/ft_isspace.c
        srcs/utils/ft_itoa.c
        srcs/utils/ft_malloc.c
        srcs/utils/ft_skip_spaces.c
        srcs/utils/ft_split.c
        srcs/utils/ft_strcmp.c
        srcs/utils/ft_strdup.c
        srcs/utils/ft_strequ.c
        srcs/utils/ft_strjoin_tripple.c
        srcs/utils/ft_strlen_shell.c
        srcs/utils/get_next_line.c
        srcs/utils/get_next_line_utils.c
        srcs/utils/init.c
        srcs/utils/show_promt.c
        srcs/utils/signals.c
        srcs/utils/two_d_array.c
        headers/get_next_line.h
        headers/minishell.h
        headers/structs.h
        srcs/utils/ft_is_export.c
        srcs/parsing/parse_utils.c
        srcs/parsing/multiline_cmd.c
        srcs/utils/is_number.c
        srcs/parsing/aggro.c
        srcs/utils/starts_with.c
        srcs/utils/ft_strnstr.c
        srcs/exec/aggreg.c)

target_link_libraries(untitled ${LIBRARY_PATH})

target_include_directories(untitled PRIVATE ../ft_printf/includes)
target_include_directories(untitled PRIVATE headers)