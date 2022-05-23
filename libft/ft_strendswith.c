/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendswith.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:21:16 by youngmki          #+#    #+#             */
/*   Updated: 2022/05/24 00:21:54 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strendswith(char *s1, char *s2)
{
	int		i;

	i = -1;
	while (s1[++i])
		if (s1[i] == s2[0])
			if (ft_strcmp(s1 + i, s2) == 0)
				return (1);
	return (0);
}
