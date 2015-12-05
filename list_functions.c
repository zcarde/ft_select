/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:34:52 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/22 03:16:00 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_files		*new_elem(char *name)
{
	t_files		*elem;

	elem = (t_files *)malloc(sizeof(t_files) * 1);
	elem->name = ft_strdup(name);
	elem->next = NULL;
	elem->previous = NULL;
	elem->selected = 0;
	return (elem);
}

void		push_back_files(t_env *env, t_files *new_elem)
{
	if (env->size_list == 0)
	{
		env->begin_l = new_elem;
		env->end_l = new_elem;
	}
	else
	{
		new_elem->next = env->begin_l;
		new_elem->previous = env->end_l;
		env->begin_l->previous = new_elem;
		env->end_l->next = new_elem;
		env->end_l = new_elem;
	}
	env->size_list++;
}

void		do_chainage(t_files *temp, t_env *env)
{
	if (env->size_list == 1)
	{
		env->begin_l = NULL;
		env->end_l = NULL;
	}
	else
	{
		if (temp == env->begin_l)
			env->begin_l = temp->next;
		if (temp == env->end_l)
			env->end_l = temp->previous;
		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
	}
}

void		del_elem_from_pos(t_env *env, int pos)
{
	t_files *temp;
	int		i;

	i = 0;
	temp = env->begin_l;
	while (i < env->size_list)
	{
		if (i == pos)
		{
			do_chainage(temp, env);
			free_elem(temp);
			break ;
		}
		temp = temp->next;
		i++;
	}
	env->size_list--;
}

t_files		*get_elem_from_pos(t_env *env, int pos)
{
	int		i;
	t_files	*temp;

	i = 0;
	temp = env->begin_l;
	while (i < pos)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}
