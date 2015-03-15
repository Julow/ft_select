/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 23:44:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/15 00:19:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "ft_colors.h"
#include <termcap.h>

static void		print_choice(t_env *env, int i)
{
	t_choice		*choice;

	choice = TG(t_choice, &(env->list), i);
	PCN(' ', CELL_MARGIN), PS((i == env->pos) ? "> " : "  ");
	if (choice->selected)
		TPS("mr");
	if (i == env->pos)
		TPS("us");
	if (choice->color != NULL && FLAG(env, FLAG_C))
		PS(choice->color);
	P(choice->data, choice->length);
	if (i == env->pos)
		TPS("ue");
	PCN(' ', env->cell_width - choice->length);
	if (choice->selected)
		TPS("me");
	if (choice->color != NULL && FLAG(env, FLAG_C))
		PS(C_RESET);
	PCN(' ', CELL_MARGIN), PS((i == env->pos) ? " <" : "  ");
}

void			print_list(t_env *env)
{
	t_pt			i;
	int				tmp;

	TPS("cl");
	i.y = 0;
	tmp = 0;
	while (i.y < env->lines)
	{
		i.x = -1;
		while (++i.x < env->columns)
		{
			tmp = env->lines * (i.x + env->col_offset) + i.y;
			if (tmp >= env->list.length)
				break ;
			print_choice(env, tmp);
		}
		if (++i.y < env->lines)
			PC('\n');
	}
	FL;
}
