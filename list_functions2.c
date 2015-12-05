/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 02:42:57 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/22 03:18:32 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		make_arg_list(int ac, char **av, t_env *env)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if ((int)ft_strlen(av[i]) + 1 > env->col_size)
			env->col_size = ft_strlen(av[i]) + 1;
		push_back_files(env, new_elem(av[i]));
		i++;
	}
}

void		free_elem(t_files *file)
{
	free(file->name);
	free(file);
}
