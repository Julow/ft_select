/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:07:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/22 15:55:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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

int				main(int argc, char **argv)
{
	t_env			env;

	ft_bzero(&env, sizeof(t_env));
	OUT(2);
	init_term(&env);
	listen_signals(&env);
	parse_argv(&env, argc, argv);
	print_list(&env);
	listen_input(&env);
	restore_term(&env);
	print_selected(&env);
	return (0);
}
