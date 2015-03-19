/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:13:45 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/19 18:08:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termcap.h>

t_bool			term_init(t_term *term)
{
	struct termios	tc;

	if ((term->name = getenv("TERM")) == NULL || tgetent(NULL, term->name) <= 0)
		term->name = DEFAULT_TERM;
	if (tgetent(NULL, term->name) <= 0)
		return (false);
	if (tcgetattr(0, &tc) < 0)
		return (false);
	ft_memcpy(&(term->save), &tc, sizeof(struct termios));
	tc.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
	tc.c_cc[VMIN] = 1;
	tc.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &tc) < 0)
		return (false);
	term->save_am = (tgetflag("am")) ? true : false;
	TPS("ti"), TPS("vi"), TPS("RA");
	term_update(term);
	return (true);
}

int				term_getchr(void)
{
	int				chr;

	chr = 0;
	if (read(0, &chr, sizeof(int)) <= 0)
		return (EOF);
	return (chr);
}

void			term_update(t_term *term)
{
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	term->width = win.ws_col;
	term->height = win.ws_row;
}

void			term_restore(t_term *term)
{
	if (term->save_am)
		TPS("SA");
	TPS("cl"), TPS("te"), TPS("ve"), FL;
	tcsetattr(0, TCSADRAIN, &(term->save));
}
