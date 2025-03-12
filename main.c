/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:13:02 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/12 11:21:39 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

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
	}
	return (0);
}
