/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_commands_utils3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:11:48 by ana-lda-          #+#    #+#             */
/*   Updated: 2025/03/16 21:12:42 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/** 
 * @brief Exits the program with a status code determined by the input command.
 * 
 * If more than one argument is provided, exits with status 1. If the first argument is not a numeric string, exits with status 255. 
 * Otherwise, converts the first argument to an integer and exits with that status.
 * 
 * @param _cmd_ The command array.
 */
void	ft_exit(char **_cmd_)
{
	int				status;

	status = 0;
	if (_cmd_[1] && _cmd_[2])
		status = 1;
	else if (_cmd_[1] && !is_string_numeric(_cmd_[1]))
		status = 255;
	else if (_cmd_[1])
		status = string_to_int(_cmd_[1]);
	free_string_array(_cmd_);
	exit(status);
}

/** 
 * @brief Checks whether the export command should print or execute the export operation.
 * 
 * Loops through the command arguments and returns 1 if at least one argument exists.
 * 
 * @param _cmd_ The command array.
 * 
 * @return 1 if export operation is valid, 0 otherwise.
 */
int	export_print_or_export(char **_cmd_)
{
	int i;

	i = 1;
	while (_cmd_[0] && _cmd_[i])
	{
		if (_cmd_[i])
			return (1);
		i++;
	}
	return (0);
}

/** 
 * @brief Checks if the export statement has a valid format.
 * 
 * Checks that the string before the `=` in the export command is a valid identifier, and that the syntax is correct.
 * 
 * @param _cmd_ The command string.
 * 
 * @return The position of the `=` if the format is valid, -1 if invalid.
 */
int	export_statment_check(char *_cmd_)
{
	int							a;
	int							b;

	a = sizeof_str(_cmd_, '=');
	if (a > 1 && _cmd_[a - 1] == '+')
		a -= 1;
	if (a)
	{
		b = 0;
		while (b < a)
		{
			if (!b && !ft_isalpha(_cmd_[b]) && _cmd_[b] != '_')
				return (-1);
			else if (b && !ft_isalnum(_cmd_[b]) && _cmd_[b] != '_')
				return (-1);
			b++;
		}
	}
	return (a);
}
