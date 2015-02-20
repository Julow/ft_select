/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 22:31:50 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/20 18:10:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>
#include <termcap.h>

void			init_env(t_env *env)
{
	ft_tabini(&(env->list), sizeof(t_choice));
	env->pos = 0;
}

void			init_term(t_env *env)
{
	char			*term;
	struct termios	tc;

	if ((term = getenv("TERM")) == NULL)
		OUT(2), PS(ERROR "Can't get the $TERM variable."), NL, exit(1);
	if (tgetent(NULL, term) <= 0)
		OUT(2), PS(ERROR "Incompatible terminal: "), PS(term), NL, exit(1);
	if (tcgetattr(0, &tc) < 0)
		OUT(2), PS(ERROR "Can't get termios attr."), NL, exit(1);
	ft_memcpy(&(env->save), &tc, sizeof(struct termios));
	tc.c_lflag &= ~(ECHO | ICANON);
	tc.c_cc[VMIN] = 1;
	if (tcsetattr(0, TCSADRAIN, &tc) < 0)
		OUT(2), PS(ERROR "Can't set termios attr."), NL, exit(1);
	TPS("vi");
	TPS("sc");
}
