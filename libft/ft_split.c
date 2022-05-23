/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 23:48:51 by iha               #+#    #+#             */
/*   Updated: 2021/07/28 16:22:05 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**splitfree(char **sp)
{
	while (*sp)
	{
		free(*sp);
		*sp++ = 0;
	}
	free(sp);
	sp = 0;
	return (NULL);
}

static char	*nextstr(char *s, char c)
{
	while (*s != c && *s)
		s++;
	while (*s == c && *s)
		s++;
	return (s);
}

static int	splitlen(char *s, char c)
{
	int	len;

	len = 0;
	while (*s)
	{
		s = nextstr(s, c);
		len++;
	}
	return (len);
}

static char	*splitstr(char *s, char c)
{
	char	*dst;
	char	*temp;
	int		size;

	temp = s;
	while (*temp != c && *temp)
		temp++;
	size = temp - s;
	dst = ft_substr(s, 0, size + 1);
	if (dst == NULL)
		return (NULL);
	dst[size] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**sp;
	char	**temp;
	char	*cur;
	int		size;

	cur = (char *)s;
	if (s == NULL)
		return (NULL);
	while (*cur == c && *cur)
		cur++;
	size = splitlen(cur, c);
	sp = ft_calloc((size + 1), sizeof(char *));
	if (sp == NULL)
		return (NULL);
	temp = sp;
	while (*cur)
	{
		*temp = splitstr(cur, c);
		if (*temp++ == NULL)
			return (splitfree(sp));
		cur = nextstr(cur, c);
	}
	*temp = NULL;
	return (sp);
}
