/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 16:04:59 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/16 14:48:50 by jaguillo         ###   ########.fr       */
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

static void		select_special(t_env *env, t_bool select)
{
	select_by_color(env, COLOR_PIPE, select);
	select_by_color(env, COLOR_BLOCK, select);
	select_by_color(env, COLOR_LINK, select);
	select_by_color(env, COLOR_SOCKET, select);
	select_by_color(env, COLOR_EXEC, select);
	select_by_color(env, COLOR_DENIED, select);
}

void			menu_select(t_env *env)
{
	int				select;
	const char		*menu[] = {"Select All", "Deselect All",

	"Select folders", "Deselect folders", "Select archives",
	"Deselect archives", "Select code", "Deselect code",
	"Select special", "Deselect special", "Select other", "Deselect other",
	"Back", NULL};
	select = ft_menu((char**)menu);
	if (select == 0 || select == 1)
		list_select_all(env, (select == 0));
	else if (select == 2 || select == 3)
		select_by_color(env, COLOR_DIR, (select == 2));
	else if (select == 4 || select == 5)
		select_by_color(env, COLOR_ARCHIVE, (select == 4));
	else if (select == 6 || select == 7)
		select_by_color(env, COLOR_CODE, (select == 6));
	else if (select == 8 || select == 9)
		select_special(env, (select == 8));
	else if (select == 10 || select == 11)
		select_by_color(env, NULL, (select == 10));
}
