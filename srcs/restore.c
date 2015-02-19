/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 22:31:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/19 22:34:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			restore_term(t_env *env)
{
	if (tcsetattr(0, TCSADRAIN, &(env->save)) < 0)
		OUT(2), PS(ERROR "Can't restore termios attr."), NL;
}
