/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:03:35 by wleite            #+#    #+#             */
/*   Updated: 2021/12/03 22:03:45 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nanoshell.h"

int	take_input(char *str)
{
	char	*buf;

	buf = readline("\001\033[93m\002>>> \001\033[0m\002");
	if (ft_strlen(buf) != 0)
	{
		add_history(buf);
		ft_strlcpy(str, buf, ft_strlen(buf) + 1);
		return (0);
	}
	else
		return (1);
}
