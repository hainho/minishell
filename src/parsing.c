#include "minishell.h"

void parsing(char **input)
{
    int     temp;
    char    buf;
    int     idx;
    int     cur_size;

    *input = (char *)malloc(sizeof(char) * 2);
    if (*input == NULL)
        exit(1);
    cur_size = 1;
    idx = 0;
    while((temp = read(0, &buf, 1)) && buf != '\n')
    {
        *input[idx++] = buf;
        *input = ft_realloc(*input, cur_size, cur_size+1);
        cur_size++;
    }
    *input[idx] = '\0';
    if (temp != 0)
    {
        free(*input);
        exit(0);
    }
    if ((ft_strchr(*input, '$') != NULL) || (ft_strchr(*input, '~') != NULL))
		*input = parse_input(*input);
}

char    *parsing_input(char *input)
{
    int     idx;
	char	*key;
	char	*temp;
    char    *parsed_input;

    idx = -1;
    parsed_input = malloc(sizeof(char));
	parsed_input[0] = 0;
    if (parsed_input == NULL)
        exit(1);
    while (input[++idx])
    {
        if (input[idx] == '$' && input[idx + 1])
            temp = ft_strjoin(parsed_input, parsing_env(input, &idx));
		else if (input[idx] == '~')
			temp = ft_strjoin(parsed_input, parse_home_path(input, 1));
		else
			temp = ft_strjoin(parsed_input, input[idx]);
		free(parsed_input);
		parsed_input = temp;
    }
	free(input);
	return (parsed_input);
}

char    *parsing_env(char *input, int *idx)
{
    char    *env_key;
    char    *env_value;

    env_key = malloc(sizeof(char));
    if (env_key == NULL)
        exit(1);
	env_key[0] = 0;
	(*idx)++;
    while (input[*idx] && !ft_isspace(input[*idx]))
        env_key = ft_strjoin(env_key, input[(*idx)++]);
    env_value = find_env_by_key(env_key, FALSE);
	if (env_value == NULL)
		return ("");
	return (env_value);
}

static char		*parse_input(char *input)
{
	int		i;
	char	*new;

	i = -1;
	new = ft_strnew(1);
	while (input[++i])
	{
		if (input[i] == '$' && input[i + 1])
		{
			new = ft_strjoincl(new, parse_env_var(input, i + 1), 0);
			while (input[i + 1] && !IS_SPACE(input[i + 1]) &&
				input[i + 1] != '$')
				i++;
		}
		else if (((i != 0 && IS_SPACE(input[i - 1])) || i == 0) &&
			input[i] == '~')
		{
			new = ft_strjoincl(new, parse_home_path(input + i, 1), 1);
			i += ft_strlen(input + i) - 1;
		}
		else
			new = ft_strjoinchcl(new, input[i]);
	}
	free(input);
	return (new);
}

static void		get_input(char **input)
{
	int		ret;
	char	buf;
	int		i;
	int		count;

	*input = ft_strnew(1);
	count = 1;
	i = 0;
	while ((ret = read(0, &buf, 1)) && buf != '\n')
	{
		*(*input + i++) = buf;
		*input = ft_realloc(*input, count, count + 1);
		count++;
	}
	*(*input + i) = '\0';
	if (!ret)
	{
		free(*input);
		exit_shell();
	}
	if ((ft_strchr(*input, '$') != NULL) || (ft_strchr(*input, '~') != NULL))
		*input = parse_input(*input);
}