/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 22:31:50 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/22 15:55:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>
#include <termcap.h>

void			init_term(t_env *env)
{
	char			*term;
	struct termios	tc;

	if ((term = getenv("TERM")) == NULL)
		PS(ERROR "Can't get the $TERM variable."), NL, exit(1);
	if (tgetent(NULL, term) <= 0)
		PS(ERROR "Incompatible terminal: "), PS(term), NL, exit(1);
	if (tcgetattr(0, &tc) < 0)
		PS(ERROR "Can't get termios attr."), NL, exit(1);
	ft_memcpy(&(env->save), &tc, sizeof(struct termios));
	tc.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
	tc.c_cc[VMIN] = 1;
	tc.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &tc) < 0)
		PS(ERROR "Can't set termios attr."), NL, exit(1);
	update_term(env);
}

void			update_term(t_env *env)
{
	env->width = tgetnum("co");
	env->height = tgetnum("li") - 1;
	TPS("ti"), TPS("vi"), TPS("sc");
}

void			restore_term(t_env *env)
{
	TCLEAR(), TPS("te"), TPS("ve"), FL;
	if (tcsetattr(0, TCSADRAIN, &(env->save)) < 0)
		PS(ERROR "Can't restore termios attr."), NL;
}
