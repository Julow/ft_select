/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:23:00 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/19 20:41:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			parse_argv(t_env *env, int argc, char **argv)
{
	int				i;
	t_choice		*tmp;

	i = 0;
	while (++i < argc)
	{
		tmp = ft_tabadd0(&(env->list));
		*tmp = (t_choice){ft_strdup(argv[i]), false};
	}
}
