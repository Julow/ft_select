/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:08:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/19 23:39:27 by jaguillo         ###   ########.fr       */
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

# define ERROR			"ft_select: Error: "

/*
** init.c
*/
void			init_env(t_env *env);
void			init_term(t_env *env);

/*
** restore.c
*/
void			restore_term(t_env *env);

/*
** argv.c
*/
void			parse_argv(t_env *env, int argc, char **argv);

#endif
