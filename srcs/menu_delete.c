/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 16:04:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/15 17:10:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "ft_colors.h"
#include <stdlib.h>

static void		delete_selection(t_env *env, t_bool select)
{
	int				i;
	int				tmp;

	if (FLAG(env->flags, FLAG_1))
	{
		list_remove(env, false);
		return ;
	}
	i = -1;
	while (++i < env->list.length)
		if (TG(t_choice, env->list, i)->selected == select)
		{
			ft_tabrem(&(env->list), i, 1);
			i--;
		}
	if (env->list.length <= 0)
		term_restore(&(env->term)), exit(1);
	tmp = env->pos;
	env->pos = 0;
	list_setpos(env, MIN(tmp, env->list.length - 1));
}

static void		delete_by_color(t_env *env, const char *color)
{
	int				i;
	int				tmp;

	if (FLAG(env->flags, FLAG_1))
		TG(t_choice, env->list, env->pos)->selected = false;
	i = -1;
	while (++i < env->list.length)
		if (ft_strequ(TG(t_choice, env->list, i)->color, color))
		{
			ft_tabrem(&(env->list), i, 1);
			i--;
		}
	if (env->list.length <= 0)
		term_restore(&(env->term)), exit(1);
	tmp = env->pos;
	env->pos = 0;
	list_setpos(env, MIN(tmp, env->list.length - 1));
}

void			menu_delete(t_env *env)
{
	int				select;
	const char		*menu[] = {"Delete selected", "Delete unselected",

	"Delete folders", "Delete archives", "Delete code", "Delete special",
	"Delete other", "Back", NULL};
	select = ft_menu((char**)menu);
	if (select == 0 || select == 1)
		delete_selection(env, (select == 0));
	else if (select == 2)
		delete_by_color(env, COLOR_DIR);
	else if (select == 3)
		delete_by_color(env, COLOR_ARCHIVE);
	else if (select == 4)
		delete_by_color(env, COLOR_CODE);
	else if (select == 5)
	{
		delete_by_color(env, COLOR_PIPE);
		delete_by_color(env, COLOR_BLOCK);
		delete_by_color(env, COLOR_LINK);
		delete_by_color(env, COLOR_SOCKET);
		delete_by_color(env, COLOR_EXEC);
		delete_by_color(env, COLOR_DENIED);
	}
	else if (select == 6)
		delete_by_color(env, NULL);
}
