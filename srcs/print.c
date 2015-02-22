/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 23:44:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/22 15:48:22 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <termcap.h>

static void		print_choice(t_env *env, int i)
{
	t_choice		*choice;

	choice = &TG(t_choice, &(env->list), i);
	if (i == env->pos)
		TPS("mr");
	PCN(' ', CELL_MARGIN);
	if (choice->selected)
		TPS("us");
	P(choice->data, choice->length);
	if (choice->selected)
		TPS("ue");
	PCN(' ', env->cell_width - choice->length + CELL_MARGIN);
	if (i == env->pos)
		TPS("me");
}

void			print_list(t_env *env)
{
	t_pt			i;
	int				tmp;
	int				cols;
	int				rows;

	TCLEAR(), FL;
	rows = MIN(env->height, env->list.length);
	cols = ft_min(env->width / env->cell_width, env->list.length / rows + 1);
	i.y = -1;
	while (++i.y < rows)
	{
		i.x = -1;
		while (++i.x < cols)
		{
			tmp = rows * i.x + i.y;
			if (tmp > env->list.length)
				break ;
			print_choice(env, tmp);
		}
		PC('\n');
	}
	FL;
}
