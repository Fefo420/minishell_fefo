/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:13:02 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/12 11:46:23 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>


void check_for_commands(char	*input)
{
	char *echo_history;
	if (input)
	{
		if (ft_strncmp(input, "echo", 4) == 0)
		{
			//skip the echo command and the space
			input += 5;
			//print the rest of the input
			ft_putstr_fd(input, 1);
			ft_putstr_fd("\n", 1);
		}
		echo_history = ft_strjoin("echo ", input);
		//add the input to the history
		add_history(echo_history);
	}
}

int	main(int argc, char **argv)
{
	//get usename, print it and use it as prompt
	char *user;
	char *prompt;
	char *input;

	(void)argc;
	(void)argv;
	//The getenv function is used to retrieve the value of an environment variable.
	user = getenv("USER");
	if (!user)
		user = "user";
	while (1)
	{
		prompt = ft_strjoin(user, "_minishell$ ");
		input = readline(prompt);
		//start building echo
		check_for_commands(input);
	}
	return (0);
}
