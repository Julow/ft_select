/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 23:44:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/14 16:59:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <termcap.h>

static void		print_choice(t_env *env, int i)
{
	t_choice		*choice;

	choice = TG(t_choice, &(env->list), i);
	if (i == env->pos)
		PCN(' ', CELL_MARGIN - 2), PS("> ");
	else
		PCN(' ', CELL_MARGIN);
	if (choice->selected)
		TPS("mr");
	if (i == env->pos)
		TPS("us");
	P(choice->data, choice->length);
	if (i == env->pos)
		TPS("ue");
	PCN(' ', env->cell_width - choice->length);
	if (choice->selected)
		TPS("me");
	if (i == env->pos)
		PCN(' ', CELL_MARGIN - 2), PS(" <");
	else
		PCN(' ', CELL_MARGIN);
}

void			print_list(t_env *env)
{
	t_pt			i;
	int				tmp;

	TPS("cl");
	i.y = -1;
	tmp = 0;
	while (++i.y < env->lines)
	{
		i.x = -1;
		while (++i.x < env->columns)
		{
			tmp = env->lines * (i.x + env->col_offset) + i.y;
			if (tmp >= env->list.length)
				break ;
			print_choice(env, tmp);
		}
		PC('\n');
	}
	FL;
}
