/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 02:44:07 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/22 03:22:34 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			get_nb_cols(t_env *env)
{
	double	res;

	if (env->size_list == 0)
		return (0);
	res = env->size_list / env->height;
	if (res - (int)res > 0)
		return ((int)res + 1);
	else
		return ((int)res);
}

int			is_window_large_enough(t_env *env)
{
	get_env()->nb_cols = get_nb_cols(env);
	if (get_env()->col_size * get_env()->nb_cols > get_env()->width)
	{
		ft_putstr_fd("Window not large enough.\nPlease enlarge the window !"
			, env->fd);
		return (0);
	}
	return (1);
}

void		get_size_term(t_env *env)
{
	struct winsize		win;

	ioctl(env->fd, TIOCGWINSZ, &win);
	env->width = win.ws_col;
	env->height = win.ws_row;
}
