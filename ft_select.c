/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:50:37 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/13 21:24:34 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			out_c(int c)
{
	ft_putchar_fd(c, get_env()->fd);
	return (0);
}

t_env		*get_env(void)
{
	static t_env env;

	return (&env);
}

void		signal_handler(int sig)
{
	if (sig == SIGTSTP)
		sigtstp_handler();
	if (sig == SIGCONT)
		sigcont_handler();
	if (sig == SIGWINCH)
		resize_handler();
	if (sig == SIGINT || sig == SIGTERM || sig == SIGKILL || sig == SIGQUIT)
		interuption_handler();
	if (sig == SIGSEGV)
		segfault_handler();
}

static void	signal_catchs(void)
{
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGWINCH, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGSEGV, signal_handler);
}

int			main(int ac, char **av, char **environ)
{
	if (init_env_struct(get_env()))
		return (-1);
	if (!isatty(0))
		print_error("Standard entry not a tty", -1, get_env(), 0);
	if (!environ[0])
		print_error("Environnement not set", -1, get_env(), 0);
	signal_catchs();
	modify_term(get_env());
	clear_term(get_env());
	if (ac == 1)
		print_error("No arguments", 0, get_env(), 1);
	make_arg_list(ac, av, get_env());
	print_list(get_env());
	move_cursor(0, 0, get_env());
	get_touche(get_env());
	if (reset_term(get_env(), 1))
		return (-1);
	return (0);
}
