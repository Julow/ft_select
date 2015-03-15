/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 18:13:22 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/15 00:08:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H

# include "libft.h"
# include <termios.h>

# define DEFAULT_TERM	"xterm"

# define TPS(s)			PS(tgetstr((s), NULL))

typedef struct	s_term
{
	char			*name;
	struct termios	save;
	t_bool			save_am;
	int				width;
	int				height;
}				t_term;

t_bool			term_init(t_term *term);
int				term_getchr(void);
void			term_update(t_term *term);
void			term_restore(t_term *term);

/*
** Keys
** -
** Return value of term_getchr()
** -
** Ascii chars have their own value as key
*/

# define KEY_ASCII(c)	(c)

# define KEY_ESC		27
# define KEY_BACK		127
# define KEY_DELETE		2117294875
# define KEY_RETURN		10
# define KEY_END		4607771

# define KEY_UP			4283163
# define KEY_LEFT		4479771
# define KEY_RIGHT		4414235
# define KEY_DOWN		4348699

# define KEY_CTRL_A		1
# define KEY_CTRL_E		5

#endif
