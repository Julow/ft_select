/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:23:12 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/03 18:23:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcat(char *s1, const char *s2)
{
	t_uint			i;
	t_uint			i2;

	i = 0;
	while (s1[i] != '\0')
		i++;
	i2 = 0;
	while (s2[i2] != '\0')
	{
		s1[i + i2] = s2[i2];
		i2++;
	}
	s1[i + i2] = '\0';
	return (s1);
}
