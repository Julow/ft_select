/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 23:44:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/02 19:03:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <termcap.h>

static void		print_choice(t_env *env, int i)
{
	t_choice		*choice;

	choice = TG(t_choice, &(env->list), i);
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
	PCN(' ', CELL_MARGIN);
}

static t_pt		table_size(t_env *env)
{
	t_pt			size;

	size = PT(0, MIN(env->height, env->list.length));
	if (size.y > 0)
		size.x = ft_min(env->width / env->cell_width,
			env->list.length / size.y + 1) + 1;
	return (size);
}

void			print_list(t_env *env)
{
	t_pt			i;
	int				tmp;
	t_pt			size;

	TPS("cl");
	size = table_size(env);
	i.y = -1;
	tmp = 0;
	while (++i.y < size.y)
	{
		i.x = -1;
		while (++i.x < size.x)
		{
			tmp = size.y * i.x + i.y;
			if (tmp >= env->list.length)
				break ;
			print_choice(env, tmp);
		}
		PC('\n');
	}
	if (tmp < env->list.length)
		PS("!WIN TOO SMALL!");
	FL;
}
