/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:00:25 by wleite            #+#    #+#             */
/*   Updated: 2021/12/03 22:01:34 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nanoshell.h"

int	parse_pipe(char *str, char **strpiped)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		strpiped[i] = strsep(&str, "|");
		if (strpiped[i] == NULL)
			break ;
	}
	if (strpiped[1] == NULL)
		return (0);
	else
		return (1);
}

void	parse_space(char *str, char **parsed)
{
	int	i;

	i = -1;
	while (++i < MAXLIST)
	{
		parsed[i] = strsep(&str, " ");
		if (parsed[i] == NULL)
			break ;
		if (strlen(parsed[i]) == 0)
			i--;
	}
}

int	process_string(char *str, char **parsed, char **parsedpipe)
{
	int		piped;
	char	*strpiped[2];

	piped = parse_pipe(str, strpiped);
	if (piped)
	{
		parse_space(strpiped[0], parsed);
		parse_space(strpiped[1], parsedpipe);
	}
	else
		parse_space(str, parsed);
	if (own_cmd_handler(parsed))
		return (0);
	else
		return (1 + piped);
}
