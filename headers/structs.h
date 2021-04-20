/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airma <airma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:24:08 by airma             #+#    #+#             */
/*   Updated: 2021/01/14 21:22:00 by airma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	struct s_queue		*tail;
	struct s_queue		*head;
	struct s_queue		*prev;
}						t_queue;

typedef struct s_shell
{
	t_queue				*env;
	t_queue				*args;
}						t_shell;

#endif
