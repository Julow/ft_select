/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:23:00 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/20 22:16:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			parse_argv(t_env *env, int argc, char **argv)
{
	int				i;
	t_choice		*tmp;
	int				len;

	ft_tabini(&(env->list), sizeof(t_choice));
	env->cell_width = CELL_MIN;
	i = 0;
	while (++i < argc)
	{
		tmp = ft_tabadd0(&(env->list));
		len = ft_strlen(argv[i]);
		*tmp = (t_choice){ft_strndup(argv[i], len), len, false};
		if (len > env->cell_width)
			env->cell_width = len;
	}
}
