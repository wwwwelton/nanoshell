/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:02:41 by wleite            #+#    #+#             */
/*   Updated: 2021/12/03 22:02:55 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nanoshell.h"

void	exec_args(char	**parsed)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		printf("\nFailed forking child..");
		return ;
	}
	else if (pid == 0)
	{
		if (execvp(parsed[0], parsed) < 0)
			printf("\nCould not execute command..");
		exit(0);
	}
	else
	{
		wait(NULL);
		return ;
	}
}

void	exec_args_piped(char **parsed, char **parsedpipe)
{
	int		fd[2];
	pid_t	p1;
	pid_t	p2;

	if (pipe(fd) < 0)
	{
		printf("\nPipe could not be initialized");
		return ;
	}
	p1 = fork();
	if (p1 < 0)
	{
		printf("\nCould not fork");
		return ;
	}
	if (p1 == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		if (execvp(parsed[0], parsed) < 0)
		{
			printf("\nCould not execute command 1..");
			exit(0);
		}
	}
	else
	{
		p2 = fork();
		if (p2 < 0)
		{
			printf("\nCould not fork");
			return ;
		}
		if (p2 == 0)
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			if (execvp(parsedpipe[0], parsedpipe) < 0)
			{
				printf("\nCould not execute command 2..");
				exit(0);
			}
		}
		else
		{
			wait(NULL);
			wait(NULL);
		}
	}
}
