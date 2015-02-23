/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 22:31:50 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/23 23:31:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termcap.h>

void			init_term(t_env *env)
{
	char			*term;
	struct termios	tc;

	if ((term = getenv("TERM")) == NULL)
		term = "";
	if (tgetent(NULL, term) <= 0 && tgetent(NULL, DEFAULT_TERM) <= 0)
		PS(ERROR "Incompatible terminal: "), PS(term), NL, exit(1);
	if (tcgetattr(0, &tc) < 0)
		PS(ERROR "Can't get termios attr."), NL, exit(1);
	ft_memcpy(&(env->save), &tc, sizeof(struct termios));
	tc.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
	tc.c_cc[VMIN] = 1;
	tc.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &tc) < 0)
		PS(ERROR "Can't set termios attr."), NL, exit(1);
	env->save_am = (tgetflag("am")) ? true : false;
	TPS("ti"), TPS("vi"), TPS("RA");
	update_term(env);
}

void			update_term(t_env *env)
{
	struct winsize	win;

	ioctl(2, TIOCGWINSZ, &win);
	env->width = win.ws_col;
	env->height = win.ws_row - 1;
}

void			restore_term(t_env *env)
{
	if (env->save_am)
		TPS("SA");
	TPS("cl"), TPS("te"), TPS("ve"), FL;
	if (tcsetattr(0, TCSADRAIN, &(env->save)) < 0)
		PS(ERROR "Can't restore termios attr."), NL;
}
