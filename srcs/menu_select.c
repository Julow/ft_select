/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 16:04:59 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/15 16:36:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "ft_colors.h"

static void		select_by_color(t_env *env, const char *color, t_bool select)
{
	int				i;

	if (FLAG(env->flags, FLAG_1))
		return ;
	i = -1;
	while (++i < env->list.length)
	{
		if (ft_strequ(TG(t_choice, env->list, i)->color, color))
			TG(t_choice, env->list, i)->selected = select;
	}
}

void			menu_select(t_env *env)
{
	int				select;
	char			*menu[10];

	menu[0] = "Select All";
	menu[1] = "Deselect All";
	menu[2] = "Select folders";
	menu[3] = "Deselect folders";
	menu[4] = "Select archives";
	menu[5] = "Deselect archives";
	menu[6] = "Select code";
	menu[7] = "Deselect code";
	menu[8] = "Back";
	menu[9] = NULL;
	select = ft_menu(menu);
	if (select == 0 || select == 1)
		list_select_all(env, (select == 0));
	else if (select == 2 || select == 3)
		select_by_color(env, COLOR_DIR, (select == 2));
	else if (select == 4 || select == 5)
		select_by_color(env, COLOR_ARCHIVE, (select == 4));
	else if (select == 6 || select == 7)
		select_by_color(env, COLOR_CODE, (select == 6));
}
