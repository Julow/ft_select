/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 21:52:46 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/14 21:55:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_bool			ft_strend(const char *str, const char *end)
{
	const char		*start_str = str;
	const char		*start_end = end;

	str += ft_strlen(str);
	end += ft_strlen(end);
	while (str > start_str && end > start_end)
		if (*(--str) != *(--end))
			return (false);
	return (true);
}
