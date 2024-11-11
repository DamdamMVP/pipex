/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:29:28 by dalebran          #+#    #+#             */
/*   Updated: 2024/11/06 05:38:57 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*search_in_paths(char **paths, char *cmd)
{
	char	*path;
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(path, cmd);
		free(path);
		if (access(full_path, F_OK) == 0)
		{
			while (paths[i])
				free(paths[i++]);
			free(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (NULL);
}

static char	*find_command_path(char *cmd, char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	return (search_in_paths(paths, cmd));
}

static void	setup_pipes(t_pipex *data, int cmd_index)
{
	if (cmd_index == 0)
	{
		dup2(data->infile, STDIN_FILENO);
		dup2(data->pipe_fd[1], STDOUT_FILENO);
	}
	else if (cmd_index == data->cmd_count - 1)
	{
		dup2(data->pipe_fd[2 * (cmd_index - 1)], STDIN_FILENO);
		dup2(data->outfile, STDOUT_FILENO);
	}
	else
	{
		dup2(data->pipe_fd[2 * (cmd_index - 1)], STDIN_FILENO);
		dup2(data->pipe_fd[2 * cmd_index + 1], STDOUT_FILENO);
	}
}

static void	child_process(t_pipex *data, char **cmd, int cmd_index)
{
	char	*cmd_path;

	setup_pipes(data, cmd_index);
	close_all_pipes(data);
	cmd_path = find_command_path(cmd[0], data->envp);
	handle_exec_error(cmd_path, cmd[0], data);
	execve(cmd_path, cmd, data->envp);
	perror(cmd_path);
	free(cmd_path);
	clear_data(data);
	exit(1);
}

void	exec_cmd(t_pipex *data, char **cmd, int cmd_index)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (perror("Fork error"));
	if (pid == 0)
		child_process(data, cmd, cmd_index);
	data->pids[cmd_index] = pid;
}
