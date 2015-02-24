/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:07:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/24 14:51:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

static void		print_selected(t_env *env)
{
	t_bool			printed;
	int				i;
	t_choice		tmp;

	printed = false;
	OUT(1);
	i = -1;
	while (++i < env->list.length)
	{
		tmp = TG(t_choice, &(env->list), i);
		if (tmp.selected)
		{
			if (printed)
				PC(' ');
			printed = true;
			PS(tmp.data);
		}
	}
	if (printed)
		NL;
}

static t_bool	parse_argv(t_env *env, int argc, char **argv)
{
	int				i;
	t_choice		*tmp;
	int				len;

	ft_tabini(&(env->list), sizeof(t_choice));
	env->cell_width = CELL_MIN;
	i = 0;
	if (ft_strequ(argv[1], "-1") && (env->flag_1 = true))
		i++;
	ft_tabext(&(env->list), argc);
	while (++i < argc)
	{
		tmp = ft_tabadd0(&(env->list));
		len = ft_strlen(argv[i]);
		*tmp = (t_choice){argv[i], len, false};
		if (len > env->cell_width)
			env->cell_width = len;
	}
	env->cell_width += CELL_MARGIN * 2;
	return ((env->list.length == 0) ? false : true);
}

static t_bool	init_fd(void)
{
	if (isatty(2))
		OUT(2);
	else if (isatty(1))
		OUT(1);
	else
		return (OUT(2), PS(ERROR "ft_select need a terminal"), NL, false);
	return (true);
}

int				main(int argc, char **argv)
{
	t_env			env;

	ft_bzero(&env, sizeof(t_env));
	listen_signals(&env);
	if (!init_fd() || !parse_argv(&env, argc, argv))
		return (1);
	list_setpos(&env, 0);
	init_term(&env);
	print_list(&env);
	listen_input(&env);
	restore_term(&env);
	print_selected(&env);
	return (0);
}
