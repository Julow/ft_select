/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:07:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/15 16:37:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

static void		print_selected(t_env *env)
{
	t_bool			printed;
	int				i;
	t_choice		*tmp;

	printed = false;
	OUT(1);
	i = -1;
	while (++i < env->list.length)
	{
		tmp = TG(t_choice, env->list, i);
		if (tmp->selected)
		{
			if (printed)
				PC(' ');
			printed = true;
			PS(tmp->data);
		}
	}
	if (printed)
		NL;
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
	if (!init_fd() || !parse_argv(&env, argc, argv) || !init_env(&env))
		return (1);
	print_list(&env);
	listen_input(&env);
	term_restore(&(env.term));
	print_selected(&env);
	return (0);
}
