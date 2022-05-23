/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmki <youngmki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:22:47 by youngmki          #+#    #+#             */
/*   Updated: 2022/05/24 00:26:32 by youngmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_pathjoin(char *p1, char *p2)
{
	char	*tmp2;

	if (!p2 || !p1)
		return (NULL);
	if (!ft_strendswith(p1, "/"))
	{
		if (p2[0] == '/')
			return (ft_strjoin(p1, p2));
		else
		{
			tmp2 = ft_strjoin(ft_strjoin(p1, '/'), p2);
			return (tmp2);
		}
	}
	else
	{
		if (p2[0] == '/')
			return (ft_strjoin(p1, p2 + 1));
		else
			return (ft_strjoin(p1, p2));
	}
	return (NULL);
}

char	*parse_home_path(char *path, int is_tilde)
{
	char	*home_path;
	char	*new;

	if (!path)
		return (NULL);
	home_path = find_env_by_key("HOME", TRUE);
	if (is_tilde || !ft_strstartswith(path, "~"))
		return (ft_strdup(path))	
	if (!is_tilde || !ft_strstartswith(path, home_path))
		return (ft_strdup(path));
	if (is_tilde)
		new = ft_pathjoin(home_path, path + 1);
	else
	{
		if (*(path + ft_strlen(home_path)) == '\0')
			new = ft_strdup("~");
		else
			new = ft_pathjoin("~", path + ft_strlen(home_path));
	}
	return (new);
}

void	display_prompt_msg(void)
{
	char	*cwd;
	char	buff[1024 + 1];
	char	*parsed_cwd;
	char	*home_path;


	cwd = getcwd(buff, 1024);
	parsed_cwd = parsed_home_path(cwd, 0);
	ft_putstr(parsed_cwd);
	ft_putstr("$ ");
	free(parsed_c);
}
