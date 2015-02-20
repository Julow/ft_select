/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:08:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/20 18:47:25 by jaguillo         ###   ########.fr       */
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
}				t_env;

typedef struct	s_choice
{
	char			*data;
	t_bool			selected;
}				t_choice;

# define INPUT_BUFF		3

# define TCLEAR()		TPS("rc"), TPS("cd")
# define TPS(s)			PS(tgetstr((s), NULL))

# define ERROR			"ft_select: Error: "

/*
** init.c
*/
void			init_env(t_env *env);
void			init_term(t_env *env);

/*
** restore.c
*/
void			restore(t_env *env);

/*
** argv.c
*/
void			parse_argv(t_env *env, int argc, char **argv);

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
void			print_selected(t_env *env);
void			print_list(t_env *env);

#endif
