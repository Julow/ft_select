/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:08:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/14 18:00:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <termios.h>

/*
** ft_select
** -
** Keys:
**  space		toggle select/deselect
**  arrows		moves
**  delete		delete an item (delete/backspace/^H)
**  ^A			select all
**  ^E			deselect all
**  RETURN		print the selection and quit
**  ESC			quit (without printing the selection)
**  All other	Search in the list
** -
** Options:
**  -1			Only one selection is possible
*/

typedef struct	s_env
{
	struct termios	save;
	t_bool			save_am;
	t_bool			flag_1;
	t_tab			list;
	int				pos;
	int				cell_width;
	int				col_offset;
	int				columns;
	int				lines;
}				t_env;

typedef struct	s_choice
{
	char			*data;
	int				length;
	t_bool			selected;
}				t_choice;

# define DEFAULT_TERM	"xterm"

# define TPS(s)			PS(tgetstr((s), NULL))

# define ERROR			"ft_select: Error: "

# define CELL_MIN		8
# define CELL_MARGIN	2

# define KEY_ESC		27
# define KEY_BACK		127
# define KEY_DELETE		2117294875
# define KEY_RETURN		10

# define KEY_UP			4283163
# define KEY_LEFT		4479771
# define KEY_RIGHT		4414235
# define KEY_DOWN		4348699

# define KEY_CTRL_A		1
# define KEY_CTRL_E		5

/*
** term.c
*/
void			init_term(t_env *env);
int				term_getchr(void);
void			update_term(t_env *env);
void			restore_term(t_env *env);

/*
** signals.c
*/
void			listen_signals(t_env *env);

/*
** input.c
*/
void			listen_input(t_env *env);

/*
** print.c
*/
void			print_list(t_env *env);

/*
** list.c
*/
void			list_setpos(t_env *env, int pos);
void			list_move(t_env *env, int key);
void			list_select(t_env *env);
void			list_select_all(t_env *env, t_bool select);
void			list_remove(t_env *env, t_bool back);

/*
** list_search.c
*/
t_bool			list_search(t_env *env, char c);

#endif
