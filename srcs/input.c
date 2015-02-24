/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 23:43:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/24 01:27:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>
#include <stdlib.h>

static void		list_move(t_env *env, int key)
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

static void		list_select(t_env *env)
{
	t_choice		*tmp;

	tmp = &TG(t_choice, &(env->list), env->pos);
	tmp->selected = (tmp->selected) ? false : true;
	list_move(env, 66);
}

static void		list_select_all(t_env *env, t_bool select)
{
	int				i;

	i = -1;
	while (++i < env->list.length)
		(&TG(t_choice, &(env->list), i))->selected = select;
}

static void		list_remove(t_env *env, t_bool back)
{
	ft_tabrem(&(env->list), env->pos, 1);
	if (env->list.length == 0)
		restore_term(env), exit(1);
	else if (env->pos >= env->list.length || (back && env->pos > 0))
		env->pos--;
}

void			listen_input(t_env *env)
{
	char			buff[INPUT_BUFF] = {0};
	int				len;

	while ((len = read(0, buff, INPUT_BUFF)) > 0)
	{
		if (len == 3 && buff[0] == 27 && buff[2] >= 65 && buff[2] <= 68)
			list_move(env, buff[2]);
		else if (len == 1 && buff[0] == 27)
			restore_term(env), exit(0);
		else if (len == 1 && buff[0] == ' ')
			list_select(env);
		else if (len == 1 && buff[0] == 10)
			return ;
		else if ((len == 1 && buff[0] == 127) || (len == 1 && buff[0] == 8))
			list_remove(env, true);
		else if (len == 4 && buff[2] == 51 && buff[3] == 126)
			list_remove(env, false);
		else if (len == 1 && buff[0] == 1)
			list_select_all(env, true);
		else if (len == 1 && buff[0] == 5)
			list_select_all(env, false);
		else
			continue ;
		print_list(env);
	}
}
