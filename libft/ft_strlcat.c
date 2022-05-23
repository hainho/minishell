/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 23:50:19 by iha               #+#    #+#             */
/*   Updated: 2021/05/19 23:50:20 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		dstlen;

	d = dst;
	s = src;
	dstlen = 0;
	while (dstsize && *d)
	{
		dstsize--;
		d++;
	}
	dstlen = d - dst;
	if (dstsize == 0)
		return (dstlen + ft_strlen(src));
	while (*s && --dstsize)
		*d++ = *s++;
	while (*s)
		s++;
	*d = 0;
	return (dstlen + s - src);
}
