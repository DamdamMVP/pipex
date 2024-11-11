/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:29:54 by dalebran          #+#    #+#             */
/*   Updated: 2024/11/06 05:41:40 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_exec_error(char *cmd_path, char *cmd_name, t_pipex *data)
{
	char	*error;

	if (!cmd_name)
	{
		write(2, "Permission denied : \n", 21);
		free(cmd_path);
		clear_data(data);
		exit(1);
	}
	else if (!cmd_path)
	{
		error = clean_join(ft_strjoin("Command not found: ", cmd_name), "\n");
		write(2, error, ft_strlen(error));
		free(error);
		clear_data(data);
		exit(1);
	}
	else if (access(cmd_path, X_OK) == -1)
	{
		error = clean_join(ft_strjoin("Permission denied: ", cmd_name), "\n");
		write(2, error, ft_strlen(error));
		(free(cmd_path), free(error));
		clear_data(data);
		exit(1);
	}
}

int	init_pipex(t_pipex *data, int ac, char **av, char **envp)
{
	int	i;

	i = 0;
	data->cmd_count = 0;
	data->infile = open(av[1], O_RDONLY, 0644);
	if (data->infile < 0)
		return (perror("Input file error"), 1);
	data->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile < 0)
		return (perror("Output file error"), 1);
	data->pids = malloc(sizeof(pid_t) * (ac - 3));
	data->pipe_fd = malloc(sizeof(int) * ((ac - 4) * 2));
	data->cmd = ft_calloc(ac - 3, sizeof(char **));
	while (i < ac - 3)
	{
		if (isfullspace(av[i + 2]))
			data->cmd[i] = ft_split(av[i + 2], 'a');
		else
			data->cmd[i] = ft_split(av[i + 2], ' ');
		data->cmd_count++;
		i++;
	}
	data->envp = envp;
	data->limiter = NULL;
	return (0);
}

int	init_pipex2(t_pipex *data, int ac, char **av, char **envp)
{
	int	i;

	i = 0;
	data->cmd_count = 0;
	data->infile = open("tmp", O_RDONLY, 0644);
	if (data->infile < 0)
		return (perror("Input file error"), 1);
	data->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (data->outfile < 0)
		return (perror("Output file error"), 1);
	data->pids = malloc(sizeof(pid_t) * (ac - 4));
	data->pipe_fd = malloc(sizeof(int) * ((ac - 5) * 2));
	data->cmd = ft_calloc(ac - 4, sizeof(char **));
	while (i < ac - 4)
	{
		if (isfullspace(av[i + 3]))
			data->cmd[i] = ft_split(av[i + 3], 'a');
		else
			data->cmd[i] = ft_split(av[i + 3], ' ');
		data->cmd_count++;
		i++;
	}
	data->envp = envp;
	return (0);
}

void	handle_here_doc(t_pipex *data, char **av)
{
	int		tmp;
	char	*line;

	tmp = open("tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp == -1)
	{
		perror("Open tmp failed ");
		clear_data(data);
		exit(1);
	}
	data->limiter = ft_strjoin(av[2], "\n");
	line = ft_get_next_line(0);
	if (!line)
		(close(tmp), free(data->limiter), exit(1));
	while (ft_strcmp(line, data->limiter) != 0)
	{
		ft_putstr_fd(line, tmp);
		free(line);
		line = ft_get_next_line(0);
		if (!line)
			(close(tmp), free(data->limiter), exit(1));
	}
	free(line);
	close(tmp);
}

void	clear_data(t_pipex *data)
{
	int	i;
	int	j;

	close(data->infile);
	close(data->outfile);
	free(data->pipe_fd);
	free(data->pids);
	free(data->limiter);
	if (data->cmd)
	{
		i = 0;
		while (i < data->cmd_count)
		{
			if (data->cmd[i])
			{
				j = 0;
				while (data->cmd[i][j])
					free(data->cmd[i][j++]);
				free(data->cmd[i]);
			}
			i++;
		}
		free(data->cmd);
	}
}
