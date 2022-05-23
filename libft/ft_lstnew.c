/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 09:35:04 by iha               #+#    #+#             */
/*   Updated: 2021/07/28 16:09:20 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tl;

	tl = (t_list *)malloc(sizeof(t_list));
	if (tl == NULL)
		return (NULL);
	tl->content = content;
	tl->next = NULL;
	return (tl);
}
