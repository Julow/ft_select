/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 16:04:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/15 16:22:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <termcap.h>

void			menu_delete(t_env *env)
{
	(void)env;
	TPS("cl"), PS("Not yet implented\n\nPress any key to quit"), NL;
	term_getchr();
}
