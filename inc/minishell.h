#include "libft.h"

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

t_env   g_env;

void	init_env(char **envv);
void	add_env(char *env_info);
char	*find_env_by_key(char *key, int is_new);
