/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 01:30:25 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/14 22:22:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>

void			list_setpos(t_env *env, int pos)
{
	if (FLAG(env, FLAG_1))
		TG(t_choice, &(env->list), env->pos)->selected = false;
	env->pos = pos;
	while ((env->pos / env->lines) > (env->col_offset + env->columns - 3))
		env->col_offset++;
	while ((env->pos / env->lines) < env->col_offset)
		env->col_offset--;
	if (FLAG(env, FLAG_1))
		TG(t_choice, &(env->list), env->pos)->selected = true;
}

void			list_move(t_env *env, int key)
{
	int				dir;

	if (key == KEY_UP)
		dir = -1;
	else if (key == KEY_DOWN)
		dir = 1;
	else if (key == KEY_RIGHT && (env->list.length - env->pos) > env->lines)
		dir = env->lines;
	else if (key == KEY_LEFT && env->pos >= env->lines)
		dir = -env->lines;
	else
		dir = 0;
	list_setpos(env, (env->pos + dir + env->list.length) % env->list.length);
}

void			list_select(t_env *env)
{
	t_choice		*tmp;

	if (FLAG(env, FLAG_1))
		return ;
	tmp = TG(t_choice, &(env->list), env->pos);
	tmp->selected = (tmp->selected) ? false : true;
	list_move(env, KEY_DOWN);
}

void			list_select_all(t_env *env, t_bool select)
{
	int				i;

	if (FLAG(env, FLAG_1))
		return ;
	i = -1;
	while (++i < env->list.length)
		TG(t_choice, &(env->list), i)->selected = select;
}

void			list_remove(t_env *env, t_bool back)
{
	ft_tabrem(&(env->list), env->pos, 1);
	if (env->list.length == 0)
		term_restore(&(env->term)), exit(1);
	else if (env->pos >= env->list.length || (back && env->pos > 0))
	{
		list_setpos(env, env->pos - 1);
		return ;
	}
	list_setpos(env, env->pos);
}
