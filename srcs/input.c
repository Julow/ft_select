/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 23:43:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/20 23:22:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

static void		move(t_env *env, int dir)
{
	env->pos = (env->pos + dir + env->list.length) % env->list.length;
}

static void		select(t_env *env)
{
	t_choice		*tmp;

	tmp = &TG(t_choice, &(env->list), env->pos);
	tmp->selected = (tmp->selected) ? false : true;
	move(env, 1);
}

void			listen_input(t_env *env)
{
	char			buff[INPUT_BUFF];
	int				len;

	while ((len = read(0, buff, INPUT_BUFF)) > 0)
	{
		if (len == 3 && buff[0] == 27 && buff[2] == 65)
			move(env, -1);
		else if (len == 3 && buff[0] == 27 && buff[2] == 66)
			move(env, 1);
		else if (len == 3 && buff[0] == 27 && buff[2] == 67)
			move(env, MIN(env->height, env->list.length));
		else if (len == 3 && buff[0] == 27 && buff[2] == 68)
			move(env, -MIN(env->height, env->list.length));
		else if (len == 1 && buff[0] == 27)
			return ;
		else if (len == 1 && buff[0] == 10)
			select(env);
		else
			continue ;
		print_list(env);
	}
}
