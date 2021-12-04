/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nanoshell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:32:45 by wleite            #+#    #+#             */
/*   Updated: 2021/12/03 22:05:28 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NANOSHELL_H
# define NANOSHELL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libraries/libft/libft.h"

# define MAXCOM 1000
# define MAXLIST 100

int		parse_pipe(char *str, char **strpiped);
void	parse_space(char *str, char **parsed);
int		process_string(char *str, char **parsed, char **parsedpipe);
void	exec_args(char	**parsed);
void	exec_args_piped(char **parsed, char **parsedpipe);
int		take_input(char *str);
void	init_shell(void);
void	clear_screen(void);
int		own_cmd_handler(char **parsed);

#endif
