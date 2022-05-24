#include "minishell.h"

void	pwd()
{
	char	*buf;
	char	*cwd;

	buf = malloc(sizeof(char) * PATH_MAX);
	if (buf == NULL)
		printf("fail to malloc buf\n");
	cwd = getcwd(buf, PATH_MAX);
	if (cwd == NULL)
		printf("getcwd error\n");
	else
		printf("%s\n", cwd);
}