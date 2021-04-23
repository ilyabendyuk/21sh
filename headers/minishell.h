/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 23:35:53 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:50:14 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <get_next_line.h>
# include "../ft_printf/includes/ft_printf.h"
# include <structs.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# define ENV_PATH 1
# define RELATIVE_PATH 0
# define PATH_ERR	2
# define OPEN_ERR	3
# define MEM_ERROR "MEMORY ERROR"

intmax_t	g_prev_err;
intmax_t	g_err;
int			g_sigint;
int			g_sigquit;
int			g_pipe[2];
int			g_fd_in;
int			g_fd_out;
int			g_save_in;
int			g_save_out;
pid_t		g_pid;
int			g_ret;
void		*ft_malloc(size_t bytes);
int			ft_strlen_shell(const char *str);
char		*ft_strdup(char *src);
void		sig_int(int code);
void		sig_quit(int code);
char		*ft_itoa_sh(int nb);
void		errors(char *error);
void		errno_err(char *cmd, int err_num, char *msg);
int			validation_error(t_queue *token, char *error);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strndup(const char *s, size_t n);
void		free_2d_array(char **arr);
char		**realloc_2d_array(char **arr, char *line);
char		**sort_2d_array(char ***array);
char		**ft_split(char const *s, char c);
char		*ft_strjoin_tripple(char *s1, char *s2, char *s3);
void		push_back(t_queue	**q, void*data);
void		*pop(t_queue **queue, void*to_del);
void		*pop_front(t_queue **queue);
char		*join_queue(t_queue *args);
void		show_promt(t_shell *shell);
int			ft_strequ(char const *s1, char const *s2);
int			ft_isspace(char c);
int			ft_is_sep_cmd(char c);
t_env		*create_env_instance(char *inst);
void		print_env(t_queue *env);
void		init_env(t_shell *shell, char **env);
char		*get_env_var(t_queue *envir, char *name);
char		*parse_env_var(t_queue *env, char **line);
int			ft_skip_spaces(char **str);
char		*parse_single_quote(char **line);
char		*parse_double_quote(t_shell *shell, char **line, t_queue *qu);
char		**assemble_env(t_queue *envir);
int			get_path(t_queue *env, char **cmd, int redir_flag);
int			count_decrease_lvl(char *path);
void		path_err(char *cmd);
void		bltn_echo(t_comand *cmd);
void		bltn_pwd(void);
void		update_env(t_queue **env, char *name, char *val);
void		bltn_cd(t_shell *shell, char *to_cd);
void		bltn_exit(t_comand *cmd, int exit_flag);
void		bltn_export(t_queue *env, char **args);
void		bltn_unset(t_queue *env, char **args);
int			open_redirs_and_check(t_shell *shell, t_comand *cmd);
void		handle_exec(t_shell *shell, t_comand *cmd, int exit_flag);
void		wait_exec(t_shell *shell, t_comand *cmd);
void		exec_last_cmd(t_shell *shell, t_comand *cmd, int exit_flag);
void		execute_cmd(t_shell *shell, t_comand *cmd, int exit_flag);
void		execute_comands(t_shell *shell, t_queue *cmd);
void		init_globals(void);
t_comand	*init_cmd_struct(void);
void		free_comands(t_queue *cmd);
void		free_tokens(t_queue *tokens);
char		*get_redir_path(char *name);
char		*parse_token(t_shell *shell, char *line, t_queue **to);
int			validate_tokens(t_queue *args);
void		parse_comands(t_shell *shell, char *line);
void		assemble_tokens_to_cmds(t_shell *shell);
void		push_redir(t_queue *cmd, t_queue **tokens);
void		push_args(t_queue *cmd, t_queue *token);
t_queue		*push_pipe(t_queue *cmd, t_queue *tokens);
int			check_redir(char *token);
int			ft_is_export(char c);
int			return_error(t_queue **c1, t_queue **q1, t_queue *c, t_queue *q);
void		*ft_free(void *ptr);

#endif