/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:08:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/14 22:11:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include "ft_term.h"

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
**  -c			Enable colors (using the right of the file)
*/

typedef struct	s_env
{
	t_term			term;
	int				flags;
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
	char			*color;
}				t_choice;

# define ERROR			"ft_select: Error: "

# define CELL_MIN		8
# define CELL_MARGIN	2

# define FLAG(e,f)		(((e)->flags) & (f))
# define FLAG_1			(1 << 1)
# define FLAG_C			(1 << 2)

# define COLOR_DIR		C_BLUE
# define COLOR_PIPE		C_YELLOW
# define COLOR_BLOCK	C_YELLOW
# define COLOR_LINK		C_CYAN
# define COLOR_SOCKET	C_MAGENTA
# define COLOR_EXEC		C_GREEN
# define COLOR_DENIED	C_GRAY
# define COLOR_ARCHIVE	C_RED
# define COLOR_CODE		C_LGRAY

/*
** term.c
*/
t_bool			init_env(t_env *env);
void			update_env(t_env *env);

/*
** signals.c
*/
void			listen_signals(t_env *env);

/*
** argv.c
*/
t_bool			parse_argv(t_env *env, int argc, char **argv);

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

/*
** utils
*/
t_bool			ft_strend(const char *str, const char *end);

#endif
