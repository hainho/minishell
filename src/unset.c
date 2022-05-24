#include "minishell.h"

void    unset(char *key)
{
    remove_env(key);
}