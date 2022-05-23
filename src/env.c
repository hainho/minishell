#include "minishell.h"

static int  get_num_of_str(char **strs)
{
	int len;

	len = 0;
	while(strs[len])
		len++;
	return (len);
}

static void	realloc_g_env()
{
	int		idx;
	char	**new_keys;
	char	**new_values;
	char	**new_envs;

	g_env.size *= 2;
	new_keys = malloc(sizeof(char *) * g_env.size + 1);
	new_values = malloc(sizeof(char *) * g_env.size + 1);
	new_envs = malloc(sizeof(char *) * g_env.size + 1);
	idx = 0;
	while (idx < g_env.num_of_env)
	{
		new_keys[idx] = g_env.keys[idx];
		new_values[idx] = g_env.values[idx];
		new_envs[idx] = g_env.envs[idx];
	}
	free(g_env.keys);
	free(g_env.values);
	free(g_env.envs);
	g_env.keys = new_keys;
	g_env.values = new_values;
	g_env.envs = new_envs;
}

void	init_env(char **envv)
{
	int idx;
	char	**cur_env_pair;

	g_env.num_of_env = get_num_of_str(envv);
	g_env.size = g_env.num_of_env * 2;
	g_env.keys = malloc(sizeof(char *) * (g_env.size + 1));
	g_env.values = malloc(sizeof(char *) * (g_env.size + 1));
	g_env.envs = malloc(sizeof(char *) * (g_env.size + 1));
	idx = 0;
	while (idx < g_env.num_of_env)
	{
		cur_env_pair = ft_split(envv[idx], '=');
		if (cur_env_pair == NULL)
			exit(1);
		if (get_num_of_str(cur_env_pair) == 1)
			g_env.values[idx] = "";
		else
			g_env.values[idx] = cur_env_pair[1];
		g_env.keys[idx] = cur_env_pair[0];
		g_env.envs[idx] = envv[idx];
		idx++;
	}
	g_env.keys[idx] = NULL;
	g_env.values[idx] = NULL;
	g_env.envs[idx] = NULL;
}

void	print_envs()
{
	int	idx;

	idx = 0;
	while (g_env.envs[idx])
		printf("%s\n", g_env.envs[idx++]);
}

void	add_env(char *env_info)
{
	int		idx;
	char	**cur_env_pair;

	cur_env_pair = ft_split(env_info, '=');
	if (cur_env_pair == NULL || get_num_of_str(cur_env_pair) != 3)
		exit(1);
	idx = find_idx_by_key(cur_env_pair[0]);
	if (idx == -1)
	{
		idx = g_env.num_of_env;
		g_env.num_of_env++;
		if (g_env.num_of_env == g_env.size)
			realloc_g_env();
		g_env.keys[idx + 1] = NULL;
		g_env.values[idx + 1] = NULL;
		g_env.envs[idx + 1] = NULL;
	}
	free(g_env.values[idx]);
	free(g_env.envs[idx]);
	g_env.values[idx] = cur_env_pair[1];
	g_env.envs[idx] = env_info;
}

static int  get_num_of_str(char **strs)
{
	int len;

	len = 0;
	while(strs[len])
		len++;
	return (len);
}

static int	find_idx_by_key(char *key)
{
	int	idx;
	int	cur_key_len;

	idx = 0;
	while(g_env.keys[idx])
	{
		cur_key_len = ft_strlen(key);
		if (ft_strncmp(g_env.keys[idx], key, cur_key_len) == 0)
			return (idx);
		idx++;
	}
	return (-1);
}

char	*find_env_by_key(char *key, int is_new)
{
	int	idx;

	idx = find_idx_by_key(key);
	if (idx == -1)
		return (NULL);
	if (is_new)
		return (ft_strdup(g_env.keys[idx]));
	return (g_env.keys[idx]);
}
