/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_catchers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 07:50:23 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/13 21:27:01 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		resize_handler(void)
{
	clear_term(get_env());
	get_size_term(get_env());
	move_cursor(0, 0, get_env());
	print_list(get_env());
	move_cursor_with_pos(get_env());
}

void		sigtstp_handler(void)
{
	char	cp[2];

	if (isatty(1))
	{
		cp[0] = get_env()->term.c_cc[VSUSP];
		cp[1] = 0;
		clear_term(get_env());
		move_cursor(0, 0, get_env());
		reset_term(get_env(), 0);
		signal(SIGTSTP, SIG_DFL);
		ioctl(get_env()->fd, TIOCSTI, cp);
		close(get_env()->fd);
	}
}

void		sigcont_handler(void)
{
	modify_term(get_env());
	reprint(get_env());
	signal(SIGTSTP, signal_handler);
}

void		interuption_handler(void)
{
	clear_term(get_env());
	move_cursor(0, 0, get_env());
	reset_term(get_env(), 1);
	exit(2);
}

void		segfault_handler(void)
{
	clear_term(get_env());
	move_cursor(0, 0, get_env());
	reset_term(get_env(), 1);
	exit(3);
}
