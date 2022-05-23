/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 23:51:37 by iha               #+#    #+#             */
/*   Updated: 2021/07/28 16:31:55 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	char	*start;
	char	*end;

	if (s1 == NULL)
		return (NULL);
	end = (char *)s1 + ft_strlen(s1) - 1;
	while (ft_strchr(set, *end) && end > s1)
		end--;
	start = (char *)s1;
	while (ft_strchr(set, *start) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(""));
	dst = malloc(end - start + 2);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, start, end - start + 2);
	dst[end - start + 1] = 0;
	return (dst);
}
