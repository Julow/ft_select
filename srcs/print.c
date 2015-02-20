/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 23:44:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/20 18:49:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <termcap.h>

void			print_selected(t_env *env)
{
	t_bool			printed;
	int				i;
	t_choice		tmp;

	printed = false;
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

void			print_list(t_env *env)
{
	int				i;
	t_choice		tmp;

	TCLEAR(), FL;
	i = -1;
	while (++i < env->list.length)
	{
		tmp = TG(t_choice, &(env->list), i);
		if (i == env->pos)
			TPS("mr");
		if (tmp.selected)
			PS("\033[4m");
		PS(tmp.data);
		PS("\033[0;0m\n");
	}
	FL;
}
