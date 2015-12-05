/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 02:40:15 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/15 20:44:00 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		print_selected_items(t_env *env)
{
	int		i;
	t_files	*temp;
	int		add;

	i = 0;
	add = 0;
	temp = env->begin_l;
	if (!temp)
		return ;
	while (i < env->size_list)
	{
		if (temp->selected)
		{
			if (add != 0)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(temp->name, 1);
			add++;
		}
		temp = temp->next;
		i++;
	}
	if (add != 0)
		ft_putstr_fd("\n", 1);
}

void		print_list(t_env *env)
{
	t_files *temp;
	int		i;

	i = 0;
	if (!is_window_large_enough(env))
		return ;
	temp = env->begin_l;
	while (i < env->size_list)
	{
		if (i == env->pos)
			start_underline(env);
		move_cursor(env->row_cursor, env->col_cursor, env);
		print_element(temp, env);
		temp = temp->next;
		i++;
		if (env->row_cursor == env->height - 1)
		{
			env->row_cursor = 0;
			env->col_cursor += env->col_size;
		}
		else
			env->row_cursor++;
		end_underline(env);
	}
	env->nb_cols = get_nb_cols(env);
}

void		reprint(t_env *env)
{
	move_cursor(0, 0, env);
	clear_term(env);
	get_size_term(env);
	print_list(env);
	move_cursor_with_pos(env);
}

void		print_element(t_files *elem, t_env *env)
{
	char *res;

	if (elem->selected)
	{
		if ((res = tgetstr("so", NULL)) == NULL)
			print_error("Error getting term str (so)", -1, env, 1);
		tputs(res, 0, out_c);
	}
	ft_putstr_fd(elem->name, env->fd);
	if (elem->selected)
	{
		if ((res = tgetstr("se", NULL)) == NULL)
			print_error("Error getting term str (se)", -1, env, 1);
		tputs(res, 0, out_c);
	}
}

void		print_error(char *error, int err_n, t_env *env, int reset)
{
	if (reset)
	{
		clear_term(env);
		reset_term(env, 1);
	}
	ft_putstr_fd("\033[31m", 2);
	ft_putendl_fd(error, 2);
	ft_putstr_fd("\033[0m", 2);
	exit(err_n);
}
