#include "minishell.h"

static char	*parse_env(char *cmd_line, int start_idx, int *idx)
{
	char	*parsed_line;
	char	*join_line;
	char	*temp;

	parsed_line = ft_strdup_range(cmd_line, start_idx, *idx);
	if (parsed_line == NULL)
		exit(1);
	(*idx)++;
	start_idx = *idx;
	while (cmd_line[*idx] && !ft_isspace(cmd_line[*idx]) && cmd_line[*idx] != '\'' && cmd_line[*idx] != '\"')
		(*idx)++;
	temp = ft_strdup_range(cmd_line, start_idx, *idx);
	join_line = find_env_by_key(temp, FALSE);
	if (join_line == NULL)
		join_line = "";
	temp = ft_strjoin(parsed_line, join_line);
	free(parsed_line);
	parsed_line = temp;
	(*idx)--;
	return (parsed_line);
}

static char	*parse_quote(char *cmd_line, int start_idx, int *idx)
{
	char	*parsed_line;
	char	*join_line;
	char	*temp;

	parsed_line = ft_strdup_range(cmd_line, start_idx, *idx);
	if (parsed_line == NULL)
		exit(1);
	(*idx)++;
	start_idx = *idx;
	while (cmd_line[*idx] && cmd_line[*idx] != '\'')
		(*idx)++;
	join_line = ft_strdup_range(cmd_line, start_idx, *idx);
	temp = ft_strjoin(parsed_line, join_line);
	free(parsed_line);
	free(join_line);
	parsed_line = temp;
	return (parsed_line);
}

static char	*parse_double_quote(char *cmd_line, int start_idx, int *idx)
{
	char	*parsed_line;
	char	*join_line;
	char	*temp;

	parsed_line = ft_strdup_range(cmd_line, start_idx, *idx);
	if (parsed_line == NULL)
		exit(1);
	(*idx)++;
	start_idx = *idx;
	while (cmd_line[*idx] && cmd_line[*idx] != '\"')
	{
		if (cmd_line[*idx] == '$')
		{
			join_line = parse_env(cmd_line, start_idx, idx);
			temp = ft_strjoin(parsed_line, join_line);
			free(parsed_line);
			free(join_line);
			parsed_line = temp;
			start_idx = (*idx) + 1;
		}
		(*idx)++;
	}
	join_line = ft_strdup_range(cmd_line, start_idx, *idx);
	temp = ft_strjoin(parsed_line, join_line);
	free(parsed_line);
	free(join_line);
	parsed_line = temp;
	return (parsed_line);
}

char	*parse_cmd_line(char *cmd_line)
{
	int     idx;
	int		start_idx;
	char	*parsed_line;
	char	*join_line;
	char	*temp;

	parsed_line = (char *)malloc(sizeof(char));
	parsed_line[0] = 0;
	idx = -1;
	start_idx = 0;
	while (cmd_line[++idx])
	{
		if (cmd_line[idx] == '$')
			join_line = parse_env(cmd_line, start_idx, &idx);
		else if (cmd_line[idx] == '\'')
			join_line = parse_quote(cmd_line, start_idx, &idx);
		else if (cmd_line[idx] == '\"')
			join_line = parse_double_quote(cmd_line, start_idx, &idx);
		else
			continue;
		temp = ft_strjoin(parsed_line, join_line);
		free(parsed_line);
		free(join_line);
		parsed_line = temp;
		start_idx = idx + 1;
	}
	if (start_idx == idx)
		return (parsed_line);
	join_line = ft_strdup_range(cmd_line, start_idx, idx);
	temp = ft_strjoin(parsed_line, join_line);
	free(parsed_line);
	free(join_line);
	parsed_line = temp;
	return (parsed_line);
}
