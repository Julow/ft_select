/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:07:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/20 14:26:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				main(int argc, char **argv)
{
	t_env			env;

	init_env(&env);
	init_term(&env);
	listen_signals(&env);
	parse_argv(&env, argc, argv);
	print_list(&env);
	listen_input(&env);
	restore_term(&env);
	return (0);
}
