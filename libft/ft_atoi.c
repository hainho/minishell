/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 23:41:29 by iha               #+#    #+#             */
/*   Updated: 2021/07/28 16:38:57 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char c)
{
	if (c == '\t' || c == '\f' || c == '\r'
		|| c == '\v' || c == '\n' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long long	n;
	int					sign;

	sign = 1;
	n = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		n = n * 10 + (*str - '0');
		str++;
		if (n >= LLONG_MAX && sign == 1)
			return (-1);
		if (n > LLONG_MAX && sign == -1)
			return (0);
	}
	return ((long long)n * sign);
}
