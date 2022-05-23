/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 23:46:09 by iha               #+#    #+#             */
/*   Updated: 2021/05/25 16:48:46 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*temp1;
	const unsigned char	*temp2;

	temp1 = s1;
	temp2 = s2;
	while (n--)
	{
		if (*temp1 != *temp2)
			return ((unsigned char)*temp1 - (unsigned char)*temp2);
		temp1++;
		temp2++;
	}
	return (0);
}
