/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 22:31:50 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/14 17:53:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>
#include <unistd.h>
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

int				term_getchr(void)
{
	int				chr;

	chr = 0;
	if (read(0, &chr, sizeof(int)) <= 0)
		return (EOF);
	return (chr);
}

void			update_term(t_env *env)
{
	struct winsize	win;

	ioctl(2, TIOCGWINSZ, &win);
	env->lines = ft_max(MIN(win.ws_row, env->list.length), 1);
	env->columns = 1;
	if (env->lines > 0)
		env->columns = ft_min(win.ws_col / env->cell_width,
			env->list.length / env->lines) + 1;
	list_setpos(env, env->pos);
}

void			restore_term(t_env *env)
{
	if (env->save_am)
		TPS("SA");
	TPS("cl"), TPS("te"), TPS("ve"), FL;
	if (tcsetattr(0, TCSADRAIN, &(env->save)) < 0)
		PS(ERROR "Can't restore termios attr."), NL;
}
