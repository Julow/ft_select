/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:07:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/20 22:03:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				main(int argc, char **argv)
{
	t_env			env;

	ft_bzero(&env, sizeof(t_env));
	init_term(&env);
	init_screen(&env);
	listen_signals(&env);
	parse_argv(&env, argc, argv);
	print_list(&env);
	listen_input(&env);
	restore(&env);
	print_selected(&env);
	return (0);
}
