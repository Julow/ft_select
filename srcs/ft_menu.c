/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 16:01:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/15 16:24:36 by jaguillo         ###   ########.fr       */
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
		PS((i == pos) ? " <\n" : "\n");
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
