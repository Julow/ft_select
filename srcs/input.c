/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 23:43:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/24 01:37:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>
#include <stdlib.h>

static t_bool	handle_key(t_env *env, char *buff, int len)
{
	if (len == 3 && buff[0] == 27 && buff[2] >= 65 && buff[2] <= 68)
		list_move(env, buff[2]);
	else if (len == 1 && buff[0] == 27)
		restore_term(env), exit(0);
	else if (len == 1 && buff[0] == ' ')
		list_select(env);
	else if ((len == 1 && buff[0] == 127) || (len == 1 && buff[0] == 8))
		list_remove(env, true);
	else if (len == 4 && buff[2] == 51 && buff[3] == 126)
		list_remove(env, false);
	else if (len == 1 && buff[0] == 1)
		list_select_all(env, true);
	else if (len == 1 && buff[0] == 5)
		list_select_all(env, false);
	else
		return (false);
	return (true);
}

void			listen_input(t_env *env)
{
	char			buff[INPUT_BUFF] = {0};
	int				len;

	while ((len = read(0, buff, INPUT_BUFF)) > 0)
	{
		if (len == 1 && buff[0] == 10)
			return ;
		else if (handle_key(env, buff, len)
			|| (len == 1 && ft_isprint(buff[0]) && list_search(env, buff[0])))
			print_list(env);
	}
}
