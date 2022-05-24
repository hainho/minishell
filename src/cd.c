#include "minishell.h"

void    cd(char *dir)
{
    if(chdir(dir) == -1)
        printf("working directory change error");
}