/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 23:43:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/14 18:01:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>

static t_bool	handle_key(t_env *env, int key)
{
	if (key == KEY_UP || key == KEY_LEFT || key == KEY_RIGHT || key == KEY_DOWN)
		list_move(env, key);
	else if (key == KEY_ESC)
		restore_term(env), exit(0);
	else if (key == ' ')
		list_select(env);
	else if (key == KEY_BACK || key == 8)
		list_remove(env, true);
	else if (key == KEY_DELETE)
		list_remove(env, false);
	else if (key == KEY_CTRL_A)
		list_select_all(env, true);
	else if (key == KEY_CTRL_E)
		list_select_all(env, false);
	else
		return (false);
	return (true);
}

void			listen_input(t_env *env)
{
	int				key;

	while ((key = term_getchr()) != EOF)
	{
		if (key == KEY_RETURN)
			return ;
		else if (handle_key(env, key)
			|| (ft_isprint(key) && list_search(env, key)))
			print_list(env);
	}
}
