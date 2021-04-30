#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_env
{
	char				*name;
	char				*value;
}						t_env;

typedef struct s_redir
{
	char				*fname;
	char				*id;
	char				*fname2;
}						t_redir;

typedef struct s_comand
{
	char				*cmd;
	char				**args;
	struct s_queue		*redir;
}						t_comand;

typedef struct s_queue
{
	void				*data;
	struct s_queue		*next;
	struct s_queue		*prev;
}						t_queue;

typedef struct s_shell
{
	t_queue				*env;
	t_queue				*args;
	int					g_pipe[2];
	int					g_fd_in;
	int					g_fd_out;
	int					g_save_in;
	int					g_save_out;
	int					g_ret;
}						t_shell;

#endif
