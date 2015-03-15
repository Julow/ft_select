/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 23:51:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/15 16:39:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			open_menu(t_env *env)
{
	int				select;
	char			*menu[6];

	menu[0] = "Select...";
	menu[1] = "Delete...";
	menu[2] = (FLAG(env->flags, FLAG_C)) ? "Disable colors" : "Enable colors";
	menu[3] = (FLAG(env->flags, FLAG_1)) ? "Disable 1-Mode" : "Enable 1-Mode";
	menu[4] = "Back";
	menu[5] = NULL;
	select = ft_menu(menu);
	if (select == 0)
		menu_select(env);
	else if (select == 1)
		menu_delete(env);
	else if (select == 2)
		env->flags ^= BIT(FLAG_C);
	else if (select == 3)
	{
		list_select_all(env, false);
		env->flags ^= BIT(FLAG_1);
		list_setpos(env, env->pos);
	}
	print_list(env);
}
