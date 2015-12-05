/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 02:49:52 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/22 03:08:59 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		down_key(t_env *env)
{
	int		pos;

	pos = env->row_cursor + (env->col_cursor / env->col_size * env->height);
	print_element(get_elem_from_pos(env, pos), env);
	if (env->row_cursor == env->height - 1)
	{
		env->row_cursor = 0;
		env->col_cursor += env->col_size;
	}
	else
		env->row_cursor++;
	pos = env->row_cursor + (env->col_cursor / env->col_size * env->height);
	if (pos == env->size_list)
	{
		env->row_cursor = 0;
		env->col_cursor = 0;
		pos = 0;
	}
	move_cursor(env->row_cursor, env->col_cursor, env);
	start_underline(env);
	print_element(get_elem_from_pos(env, pos), env);
	move_cursor(env->row_cursor, env->col_cursor, env);
	end_underline(env);
	return (pos);
}

int		up_key(t_env *env)
{
	int		pos;

	pos = env->row_cursor + (env->col_cursor / env->col_size * env->height);
	print_element(get_elem_from_pos(env, pos), env);
	if (env->row_cursor == 0)
	{
		env->row_cursor = env->height;
		env->col_cursor -= env->col_size;
	}
	env->row_cursor--;
	if (pos == 0)
	{
		env->row_cursor = (int)env->height - 1
			- (env->nb_cols * (int)env->height - (int)env->size_list);
		env->col_cursor = (env->nb_cols - 1) * env->col_size;
		pos = env->size_list - 1;
	}
	else
		pos = env->row_cursor + (env->col_cursor / env->col_size * env->height);
	move_cursor(env->row_cursor, env->col_cursor, env);
	start_underline(env);
	print_element(get_elem_from_pos(env, pos), env);
	move_cursor(env->row_cursor, env->col_cursor, env);
	end_underline(env);
	return (pos);
}

int		left_key(t_env *env)
{
	int		pos;

	pos = env->row_cursor +
		(env->col_cursor / env->col_size * (int)env->height);
	if (env->col_cursor == 0)
		return (pos);
	print_element(get_elem_from_pos(env, pos), env);
	env->col_cursor -= env->col_size;
	pos = env->row_cursor +
		(env->col_cursor / env->col_size * (int)env->height);
	move_cursor(env->row_cursor, env->col_cursor, env);
	start_underline(env);
	print_element(get_elem_from_pos(env, pos), env);
	move_cursor(env->row_cursor, env->col_cursor, env);
	end_underline(env);
	return (pos);
}

int		right_key(t_env *env)
{
	int		pos;

	pos = env->row_cursor + (env->col_cursor / env->col_size * env->height);
	if (env->col_cursor == (env->nb_cols - 1) * env->col_size)
		return (pos);
	if (env->col_cursor / env->col_size == env->nb_cols - 2)
		if (env->row_cursor >= env->size_list -
			((env->nb_cols - 1) * env->height))
			return (pos);
	print_element(get_elem_from_pos(env, pos), env);
	env->col_cursor += env->col_size;
	pos = env->row_cursor + (env->col_cursor / env->col_size * env->height);
	move_cursor(env->row_cursor, env->col_cursor, env);
	start_underline(env);
	print_element(get_elem_from_pos(env, pos), env);
	move_cursor(env->row_cursor, env->col_cursor, env);
	end_underline(env);
	return (pos);
}

int		space_key(t_env *env)
{
	int		pos;

	pos = env->row_cursor + (env->col_cursor / env->col_size * env->height);
	get_elem_from_pos(env, pos)->selected =
		((get_elem_from_pos(env, pos)->selected) ? 0 : 1);
	print_element(get_elem_from_pos(env, pos), env);
	move_cursor(env->row_cursor, env->col_cursor, env);
	pos = down_key(env);
	end_underline(env);
	return (pos);
}
