/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 02:52:31 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/13 21:24:13 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		reset_term(t_env *e, int clos)
{
	struct termios	term;
	char			*term_name;
	char			*res;

	if ((term_name = getenv("TERM")) == NULL)
		print_error("Error getting term name", -1, e, 1);
	if (tgetent(NULL, term_name) == ERR)
		print_error("Error getting term ent", -1, e, 1);
	if (tcgetattr(e->fd, &term) == -1)
		print_error("Error getting term attrs", -1, e, 1);
	if ((res = tgetstr("ve", NULL)) == NULL)
		print_error("Error getting term str (ve)", -1, e, 0);
	tputs(res, 0, out_c);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_lflag |= ISIG;
	if (tcsetattr(e->fd, TCSADRAIN, &term) == -1)
		return (-1);
	if (clos)
		close(e->fd);
	return (0);
}

void	modify_term(t_env *env)
{
	struct termios	term;
	char			*term_name;

	if ((term_name = getenv("TERM")) == NULL)
		print_error("Error getting term name", -1, env, 1);
	if (tgetent(NULL, term_name) == ERR)
		print_error("Error getting term ent", -1, env, 1);
	if ((env->fd = open(ttyname(STDIN_FILENO), O_RDWR)) == -1)
		print_error("Error opening tty", -1, env, 1);
	if (tcgetattr(env->fd, &term) == -1)
		print_error("Error getting term attrs", -1, env, 1);
	env->term = term;
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_lflag |= ISIG;
	term.c_cc[VMIN] = 0;
	term.c_cc[VTIME] = 1;
	if (tcsetattr(env->fd, TCSADRAIN, &term) == -1)
		print_error("Error setting term args", -1, env, 1);
	get_size_term(env);
}

void	clear_term(t_env *env)
{
	char *res;

	if ((res = tgetstr("ho", NULL)) == NULL)
		print_error("Error getting term str (ho)", -1, env, 0);
	tputs(res, 0, out_c);
	if ((res = tgetstr("cd", NULL)) == NULL)
		print_error("Error getting term str (cd)", -1, env, 0);
	tputs(res, 0, out_c);
	if ((res = tgetstr("vi", NULL)) == NULL)
		print_error("Error getting term str (vi)", -1, env, 0);
	tputs(res, 0, out_c);
}

void	start_underline(t_env *env)
{
	char *res;

	if ((res = tgetstr("us", NULL)) == NULL)
		print_error("Error getting term str (us)", -1, env, 1);
	tputs(res, 0, out_c);
}

void	end_underline(t_env *env)
{
	char *res;

	if ((res = tgetstr("ue", NULL)) == NULL)
		print_error("Error getting term str (ue)", -1, env, 1);
	tputs(res, 0, out_c);
}
