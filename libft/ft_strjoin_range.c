/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_range.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 03:30:40 by youngmki          #+#    #+#             */
/*   Updated: 2022/05/24 03:30:46 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_range(char const *s1, char const *s2, int start, int end)
{
	char	*dst;
	char	*temp;
	int		n;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *)malloc(n * sizeof(char));
	if (dst == NULL)
		return (NULL);
	temp = dst;
	while (*s1)
		*temp++ = *s1++;
	i = start;
	while (s2[i] && i < end)
		*temp++ = s2[i++];
	*temp = 0;
	return (dst);
}
