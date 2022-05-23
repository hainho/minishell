/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 23:45:57 by iha               #+#    #+#             */
/*   Updated: 2021/05/19 23:54:17 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp;
	unsigned char		uc;

	uc = c;
	temp = s;
	while (n--)
	{
		if (*temp == uc)
			return ((unsigned char *)temp);
		temp++;
	}
	return (0);
}
