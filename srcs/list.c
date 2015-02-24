/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 01:30:25 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/24 01:31:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>

void			list_move(t_env *env, int key)
{
	int				dir;

	if (key == 65)
		dir = -1;
	else if (key == 66)
		dir = 1;
	else if (key == 67 && (env->list.length - env->pos) > env->height)
		dir = env->height;
	else if (key == 68 && env->pos >= env->height)
		dir = -env->height;
	else
		dir = 0;
	env->pos = (env->pos + dir + env->list.length) % env->list.length;
}

void			list_select(t_env *env)
{
	t_choice		*tmp;

	tmp = &TG(t_choice, &(env->list), env->pos);
	tmp->selected = (tmp->selected) ? false : true;
	list_move(env, 66);
}

void			list_select_all(t_env *env, t_bool select)
{
	int				i;

	i = -1;
	while (++i < env->list.length)
		(&TG(t_choice, &(env->list), i))->selected = select;
}

void			list_remove(t_env *env, t_bool back)
{
	ft_tabrem(&(env->list), env->pos, 1);
	if (env->list.length == 0)
		restore_term(env), exit(1);
	else if (env->pos >= env->list.length || (back && env->pos > 0))
		env->pos--;
}
