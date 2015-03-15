/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 23:51:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/15 00:39:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <termcap.h>

static void		refresh_menu(char **menu, int pos)
{
	int				i;

	TPS("cl");
	PS("\n    Menu\n\n");
	i = -1;
	while (menu[++i] != NULL)
	{
		PS((i == pos) ? "  > " : "    ");
		PS(menu[i]);
		PCN(' ', 14 - ft_strlen(menu[i]));
		PS((i == pos) ? " <" : "  ");
		PC('\n');
	}
	FL;
}

int				ft_menu(char **menu)
{
	int				count;
	int				key;
	int				pos;

	count = 0;
	while (menu[count] != NULL)
		count++;
	pos = 0;
	refresh_menu(menu, pos);
	while ((key = term_getchr()) != EOF)
	{
		if (key == KEY_UP)
			pos = (pos - 1 + count) % count;
		else if (key == KEY_DOWN)
			pos = (pos + 1) % count;
		else if (key == KEY_RETURN)
			return (pos);
		else if (key == KEY_ESC)
			return (-1);
		else
			continue ;
		refresh_menu(menu, pos);
	}
	return (-1);
}

void			open_menu(t_env *env)
{
	int				select;
	char			*menu[6];

	menu[0] = "Select all";
	menu[1] = "Deselect all";
	menu[2] = (FLAG(env, FLAG_C)) ? "Disable colors" : "Enable colors";
	menu[3] = (FLAG(env, FLAG_1)) ? "Disable 1-Mode" : "Enable 1-Mode";
	menu[4] = "Back";
	menu[5] = NULL;
	select = ft_menu(menu);
	if (select == 0)
		list_select_all(env, true);
	else if (select == 1)
		list_select_all(env, false);
	else if (select == 2)
		env->flags ^= FLAG_C;
	else if (select == 3)
	{
		list_select_all(env, false);
		env->flags ^= FLAG_1;
		list_setpos(env, env->pos);
	}
	print_list(env);
}
