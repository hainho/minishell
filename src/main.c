#include "minishell.h"

int main(int ac, char **av, char **envs)
{
	(void)ac;
	(void)av;
	init_env(envs);
	display_prompt_msg();
	ft_putstr_fd("ndf", 1);
}