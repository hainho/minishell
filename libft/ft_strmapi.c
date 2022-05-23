/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 23:50:51 by iha               #+#    #+#             */
/*   Updated: 2021/07/28 16:28:36 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	size_t			len;
	unsigned int	n;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	n = 0;
	while (s[n])
	{
		dst[n] = f(n, s[n]);
		n++;
	}
	dst[n] = 0;
	return (dst);
}
