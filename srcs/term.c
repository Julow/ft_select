/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 22:31:50 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/14 20:30:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_bool			init_env(t_env *env)
{
	if (!term_init(&(env->term)))
	{
		OUT(2), PS(ERROR "Cannot init the terminal"), NL;
		return (false);
	}
	update_env(env);
	return (true);
}

void			update_env(t_env *env)
{
	env->lines = ft_max(MIN(env->term.height, env->list.length), 1);
	env->columns = 1;
	if (env->lines > 0)
		env->columns = ft_min(env->term.width / env->cell_width,
			env->list.length / env->lines) + 1;
	list_setpos(env, env->pos);
}
