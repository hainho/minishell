#include "minishell.h"

int main(int av, char **ac)
{
	(void)av;
	char *arr1;

	arr1 = ac[1];

	printf("%s", ft_strdup_range(ac[1], 1, 5));
}