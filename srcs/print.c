/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 23:44:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/20 18:09:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <termcap.h>

void			clear_screen()
{
	TPS("rc");
	TPS("cd");
}

void			print_list(t_env *env)
{
	int				i;
	t_choice		tmp;

	clear_screen();
	i = -1;
	while (++i < env->list.length)
	{
		tmp = TG(t_choice, &(env->list), i);
		if (tmp.selected)
			PS("\033[4m");
		if (i == env->pos)
			TPS("mr");
		PS(tmp.data);
		PS("\033[0;0m\n");
	}
	FL;
}
