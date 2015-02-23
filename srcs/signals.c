/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 13:23:11 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/23 23:40:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <signal.h>
#include <stdlib.h>
#include <termcap.h>
#include <sys/ioctl.h>

#define ENV		(env_save(NULL))

static t_env	*env_save(t_env *env)
{
	static t_env	*save;

	if (env != NULL)
		save = env;
	return (save);
}

static void		sig_handler(int sig)
{
	if (sig == SIGWINCH)
	{
		update_term(ENV);
		print_list(ENV);
	}
	else if (sig == SIGTSTP)
	{
		restore_term(ENV);
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, "\032");
	}
	else if (sig == SIGCONT)
	{
		listen_signals(ENV);
		init_term(ENV);
		print_list(ENV);
	}
	else if (sig != SIGCHLD && sig != SIGURG && sig != SIGIO)
	{
		restore_term(ENV);
		exit(0);
	}
}

void			listen_signals(t_env *env)
{
	int				i;

	env_save(env);
	i = -1;
	while (++i < 32)
		signal(i, &sig_handler);
}
