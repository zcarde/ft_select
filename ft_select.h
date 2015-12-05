/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:50:45 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/13 21:22:23 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <curses.h>
# include <term.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <signal.h>
# include "libft.h"

typedef struct		s_files
{
	char			*name;
	int				selected;
	struct s_files	*next;
	struct s_files	*previous;
}					t_files;

typedef struct		s_env
{
	t_files			*begin_l;
	t_files			*end_l;
	double			size_list;
	struct termios	term;
	double			width;
	double			height;
	int				col_size;
	int				col_cursor;
	int				row_cursor;
	int				nb_cols;
	int				pos;
	int				fd;
}					t_env;

int					out_c(int c);
t_env				*get_env(void);
void				signal_handler(int sig);

void				resize_handler(void);
void				sigtstp_handler(void);
void				interuption_handler(void);
void				sigcont_handler(void);
void				segfault_handler(void);

void				print_selected_items(t_env *env);
void				print_list(t_env *env);
void				reprint(t_env *env);
void				print_element(t_files *elem, t_env *env);
void				print_error(char *error, int err_n, t_env *env, int reset);

t_files				*get_elem_from_pos(t_env *env, int pos);
void				del_elem_from_pos(t_env *env, int pos);
void				do_chainage(t_files *temp, t_env *env);
void				push_back_files(t_env *env, t_files *new_elem);
t_files				*new_elem(char *name);

void				make_arg_list(int ac, char **av, t_env *env);
void				free_elem(t_files *file);

int					get_nb_cols(t_env *env);
int					is_window_large_enough(t_env *env);
void				get_size_term(t_env *env);

int					down_key(t_env *env);
int					up_key(t_env *env);
int					left_key(t_env *env);
int					right_key(t_env *env);
int					space_key(t_env *env);

void				del_key(t_env *env);
void				return_key(t_env *env);
void				check_key(char *buff, t_env *env);
void				get_touche(t_env *env);

int					reset_term(t_env *e, int close);
void				modify_term(t_env *env);
void				clear_term(t_env *env);
void				start_underline(t_env *env);
void				end_underline(t_env *env);

void				move_cursor_with_pos(t_env *env);
void				move_cursor(int row, int col, t_env *env);

int					init_env_struct(t_env *e);

#endif
