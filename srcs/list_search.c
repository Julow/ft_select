/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 01:32:44 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/24 13:59:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		search_c(t_tab *list, int start, int end, char c)
{
	while (start < end)
	{
		if ((&TG(t_choice, list, start))->data[0] == c)
			return (start);
		start++;
	}
	return (-1);
}

t_bool			list_search(t_env *env, char c)
{
	int				i;

	if ((i = search_c(&(env->list), env->pos + 1, env->list.length, c)) >= 0
		|| (i = search_c(&(env->list), 0, env->pos + 1, c)) >= 0)
		return (list_setpos(env, i), true);
	return (false);
}
