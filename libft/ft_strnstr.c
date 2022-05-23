/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 23:51:12 by iha               #+#    #+#             */
/*   Updated: 2021/05/19 23:57:52 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	nlen;
	size_t	hlen;

	if (*needle == 0)
		return ((char *)haystack);
	nlen = ft_strlen(needle);
	hlen = ft_strlen(haystack);
	while (len-- >= nlen && hlen-- >= nlen)
	{
		if (*haystack == *needle)
		{
			n = 0;
			while (*(needle + n) && (*(haystack + n) == *(needle + n)))
				n++;
			if (*(needle + n) == 0)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (0);
}
