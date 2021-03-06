/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nanoshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:26:26 by wleite            #+#    #+#             */
/*   Updated: 2021/12/03 22:04:11 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nanoshell.h"

int	main(void)
{
	char	input_string[MAXCOM];
	char	*parsed_args[MAXLIST];
	char	*parsed_args_piped[MAXLIST];
	int		exec_flag;

	exec_flag = 0;
	init_shell();
	while (1)
	{
		if (take_input(input_string))
			continue ;
		exec_flag = process_string(input_string, parsed_args,
				parsed_args_piped);
		if (exec_flag == 1)
			exec_args(parsed_args);
		if (exec_flag == 2)
			exec_args_piped(parsed_args, parsed_args_piped);
	}
	return (0);
}
