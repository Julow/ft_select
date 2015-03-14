/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 20:50:42 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/14 21:10:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		parse_options(t_env *env, int argc, char **argv)
{
	int				i;
	int				j;
	int				flags;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] != '-' || argv[i][1] == '\0')
			break ;
		flags = 0;
		j = 0;
		while (argv[i][++j] != '\0')
			if (argv[i][j] == '1')
				flags |= FLAG_1;
			else
				return ((ft_strequ(argv[i], "--")) ? i + 1 : i);
		env->flags |= flags;
	}

	return (i);
}

static t_bool	parse_list(t_env *env, int argc, char **argv)
{
	int				i;
	t_choice		*tmp;
	int				len;

	ft_tabini(&(env->list), sizeof(t_choice));
	env->cell_width = CELL_MIN;
	ft_tabext(&(env->list), argc);
	i = 0;
	while (i < argc)
	{
		tmp = ft_tabadd0(&(env->list));
		len = ft_strlen(argv[i]);
		*tmp = (t_choice){argv[i], len, false};
		if (len > env->cell_width)
			env->cell_width = len;
		i++;
	}
	env->cell_width += CELL_MARGIN * 2;
	return ((env->list.length == 0) ? false : true);
}

t_bool			parse_argv(t_env *env, int argc, char **argv)
{
	int				tmp;

	if ((tmp = parse_options(env, argc, argv)) < 0)
		return (false);
	return (parse_list(env, argc - tmp, argv + tmp));
}
