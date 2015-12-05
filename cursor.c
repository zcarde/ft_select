/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 02:55:49 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/22 02:58:00 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_cursor(int row, int col, t_env *env)
{
	char *res;

	if ((res = tgetstr("cm", NULL)) == NULL)
		print_error("Error getting term str (cm)", -1, env, 1);
	tputs(tgoto(res, col, row), 0, out_c);
	env->row_cursor = row;
	env->col_cursor = col;
}

void	move_cursor_with_pos(t_env *env)
{
	int	row;
	int	col;

	row = (env->pos) % (int)env->height;
	col = (env->pos / (int)env->height) * env->col_size;
	move_cursor(row, col, env);
}
