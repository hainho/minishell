#include "minishell.h"

int main(int av, char **ac, char **envs)
{
	char	*cmd_line;
	char	*parsed_line;

	(void)av;
	(void)ac;
	init_env(envs);
	display_prompt_msg();
	// printf("%s\n", find_env_by_key("HOME", FALSE));
	// cmd_line = "echo $HOME quote '$HOME\"1 2 3\"' double quote \"123 $HOME '123' 123\" ";
	cmd_line = "echo 123 $HOME \' $HOME    123\'\"$HOME asd\"";

	// cmd_line = ft_strdup_range(cmd_line, 1,6);
	// printf("%s",cmd_line);

	parsed_line = parse_cmd_line(cmd_line);
	printf("\n%s\n", parsed_line);
	return (0);
}