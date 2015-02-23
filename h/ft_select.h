/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 19:08:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/23 18:57:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <termios.h>

/*
** Signals
** --
** Signal	Name		Action			Comment
** --
**  1		SIGHUP		Terminate		Hangup or Parent terminated
**  2		SIGINT		Terminate		^\
**  3		SIGQUIT		Core			^C
**  4		SIGILL		Core			Illegal Instruction
**  5		SIGTRAP		Core			Breakpoint
**  6		SIGABRT		Core			Abort
**  7		SIGBUS		Core			Bus error
**  8		SIGFPE		Core			Floating point exception
**  9		SIGKILL		! Terminate		Kill
**  10		SIGUSR1		Terminate		User 1
**  11		SIGSEGV		Core			Segmentation fault
**  12		SIGUSR2		Terminate		User 2
**  13		SIGPIPE		Terminate		Broken pipe
**  14		SIGALRM		Terminate		Timer
**  15		SIGTERM		Terminate		Terminate
**  16		SIGSTKFLT	Terminate		Stack fault
**  17		SIGCHLD		Ignore			Child terminated
**  18		SIGCONT		Continue		Continue after a Stop
**  19		SIGSTOP		! Stop			Stop
**  20		SIGTSTP		Stop			Stop
**  21		SIGTTIN		Stop			Terminal input
**  22		SIGTTOU		Stop			Terminal output
**  23		SIGURG		Ignore			Urgent
**  24		SIGXCPU		Core			CPU time limit
**  25		SIGXFSZ		Core			File size limit
**  26		SIGVTALRM	Terminate		Virtual alarm
**  27		SIGPROF		Terminate		Profiling timer
**  28		SIGWINCH	Ignore			Window resize
**  29		SIGIO		Terminate		-
**  30		SIGPWR		Terminate		Power failure
**  31		SIGSYS		Core			-
** --
*/

typedef struct	s_env
{
	struct termios	save;
	t_bool			save_am;
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
