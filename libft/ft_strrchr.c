/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 23:51:22 by iha               #+#    #+#             */
/*   Updated: 2021/06/23 19:34:40 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	char			*temp;

	uc = c;
	temp = 0;
	while (*s)
	{
		if (*s == uc)
			temp = (char *)s;
		s++;
	}
	if (*s == uc)
		temp = (char *)s;
	return (temp);
}
