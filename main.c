/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:13:02 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/12 12:31:12 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>


char *check_for_commands(char	*input)
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
			echo_history = ft_strjoin("echo ", input);
			//add the input to the history
			return (echo_history);
		}
		else if (ft_strncmp(input, "clear", 5) == 0)
		{
			//clear the screen
			rl_clear_history();
			return (input);
		}

	}
	return (input);
}

int	main(void)
{
	//get usename, print it and use it as prompt
	char *user;
	char *prompt;
	char *input;
	char *history;

	//The getenv function is used to retrieve the value of an environment variable.
	user = getenv("USER");
	if (!user)
		user = "user";
	while (1)
	{
		prompt = ft_strjoin(user, "_minishell$ ");
		input = readline(prompt);
		//start building echo
		history = check_for_commands(input);
		add_history(history);
	}
	return (0);
}
