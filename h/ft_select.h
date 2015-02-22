/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:08:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/22 17:11:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <termios.h>

typedef struct	s_env
{
	struct termios	save;
	t_tab			list;
	int				pos;
	int				cell_width;
	int				width;
	int				height;
}				t_env;

typedef struct	s_choice
{
	char			*data;
	int				length;
	t_bool			selected;
}				t_choice;

# define INPUT_BUFF		4

# define TCLEAR()		TPS("cl")
# define TPS(s)			PS(tgetstr((s), NULL))

# define ERROR			"ft_select: Error: "

# define CELL_MIN		8
# define CELL_MARGIN	2

/*
** term.c
*/
void			init_term(t_env *env);
void			update_term(t_env *env);
void			restore_term(t_env *env);

/*
** argv.c
*/
t_bool			parse_argv(t_env *env, int argc, char **argv);

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

#endif
