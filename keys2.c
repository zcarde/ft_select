/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 02:50:52 by zcarde            #+#    #+#             */
/*   Updated: 2015/04/16 16:13:43 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	del_key(t_env *env)
{
	if (env->pos == env->size_list - 1)
	{
		env->pos = up_key(env);
		del_elem_from_pos(env, env->pos + 1);
	}
	else
		del_elem_from_pos(env, env->pos);
	if (env->size_list == 0)
	{
		reset_term(env, 1);
		exit(0);
	}
	reprint(env);
}

void	return_key(t_env *env)
{
	clear_term(env);
	reset_term(env, 1);
	print_selected_items(env);
	exit(0);
}

void	check_key(char *buff, t_env *env)
{
	if (buff[0] == '\033')
	{
		if (buff[2] == 'A')
			env->pos = up_key(env);
		else if (buff[2] == 'B')
			env->pos = down_key(env);
		else if (buff[2] == 'D')
			env->pos = left_key(env);
		else if (buff[2] == 'C')
			env->pos = right_key(env);
		else if (buff[2] == '3' && buff[3] == '~')
			del_key(env);
		else if (buff[2] == 0)
			print_error("Exit", 0, env, 1);
	}
	else if (buff[0] == ' ')
		env->pos = space_key(env);
	else if (buff[0] == '\n')
		return_key(env);
	else if (buff[0] == 8 || buff[0] == 127)
		del_key(env);
}

void	get_touche(t_env *env)
{
	char	buff[4];

	while (1)
	{
		read(0, buff, 4);
		check_key(buff, env);
		ft_bzero(buff, 4);
	}
}
