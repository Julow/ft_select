/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 23:43:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/20 00:36:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

void			listen_input(t_env *env)
{
	char			buff[INPUT_BUFF];
	int				len;

	while ((len = read(0, buff, INPUT_BUFF)) > 0)
	{
		if (len == 3 && buff[0] == 27 && buff[2] == 65)
			env->pos = (env->pos - 1 + env->list.length) % env->list.length;
		else if (len == 3 && buff[0] == 27 && buff[2] == 66)
			env->pos = (env->pos + 1 + env->list.length) % env->list.length;
		else if (len == 1 && buff[0] == 27)
			restore(env);
		print_list(env);
	}
}
