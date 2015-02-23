/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 13:23:11 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/23 00:56:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <signal.h>
#include <stdlib.h>
#include <termcap.h>

static t_env	*env_save(t_env *env)
{
	static t_env	*save;

	if (env != NULL)
		save = env;
	return (save);
}

static void		sigwinch_handler(int sig)
{
	update_term(env_save(NULL));
	print_list(env_save(NULL));
	(void)sig;
}

static void		sig_handler(int sig)
{
	restore_term(env_save(NULL));
	exit(0);
	(void)sig;
}

void			listen_signals(t_env *env)
{
	int				i;

	env_save(env);
	i = -1;
	while (++i < 32)
	{
		if (i != SIGCHLD && i != SIGURG && i != SIGWINCH && i != SIGIO
			&& i != SIGCONT && i != SIGKILL && i != SIGSTOP)
			signal(i, &sig_handler);
	}
	signal(SIGWINCH, &sigwinch_handler);
}
