/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:02:03 by wleite            #+#    #+#             */
/*   Updated: 2021/12/03 22:02:09 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nanoshell.h"

int	own_cmd_handler(char **parsed)
{
	int		no_of_own_cmds;
	int		switch_own_arg;
	int		i;
	char	*list_of_own_cmds[2];

	switch_own_arg = 0;
	list_of_own_cmds[0] = "exit";
	list_of_own_cmds[1] = "cd";

	no_of_own_cmds = 2;
	i = -1;
	while (++i < no_of_own_cmds)
	{
		if (strcmp(parsed[0], list_of_own_cmds[i]) == 0)
		{
			switch_own_arg = i + 1;
			break ;
		}
	}
	switch (switch_own_arg)
	{
	case 1:
		printf("\nGoodbye\n");
		exit(0);
	case 2:
		chdir(parsed[1]);
		return 1;
	default:
		break;
	}
	return (0);
}
