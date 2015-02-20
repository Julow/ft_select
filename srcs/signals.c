/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 13:23:11 by jaguillo          #+#    #+#             */
/*   Updated: 2015/02/20 23:40:51 by jaguillo         ###   ########.fr       */
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

static void		sig_handler(int sig)
{
	if (sig == SIGWINCH)
	{
		TCLEAR(), FL;
		init_screen(env_save(NULL));
		print_list(env_save(NULL));
		return ;
	}
	restore(env_save(NULL));
	exit(0);
}

void			listen_signals(t_env *env)
{
	int				i;

	env_save(env);
	i = -1;
	while (++i < 32)
		signal(i, &sig_handler);
}
