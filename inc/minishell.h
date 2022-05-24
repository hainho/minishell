#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "stdio.h"
# include <readline/readline.h>

# define TRUE 1
# define FALSE 0
typedef struct s_env
{
	int		size;
	int		num_of_env;
	char	**keys;
	char	**values;
	char	**envs;
}				t_env;

t_env	g_env;

void	init_env(char **envv);
void	add_env(char *env_info);
char	*find_env_by_key(char *key, int is_new);
char	*parse_home_path(char *path, int is_tilde);
void	display_prompt_msg(void);
char	*parse_home_path(char *path, int is_tilde);
char	*ft_pathjoin(char *p1, char *p2);
void	print_envs();
char	*parse_cmd_line(char *cmd_line);
void	echo(char **strs);

#endif