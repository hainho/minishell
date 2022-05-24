#include "minishell.h"

void	echo(char **strs)
{
	int	idx;

	idx = 0;
	while(strs[idx])
	{
		printf("%s", strs[idx++]);
		if (strs[idx] != NULL)
			printf(" ");
	}
}
