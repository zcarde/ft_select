/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 02:57:01 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/22 02:57:15 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		init_env_struct(t_env *e)
{
	e->begin_l = NULL;
	e->end_l = NULL;
	e->size_list = 0;
	e->col_size = 0;
	e->col_cursor = 0;
	e->row_cursor = 0;
	e->nb_cols = 0;
	e->pos = 0;
	e->fd = 1;
	return (0);
}
