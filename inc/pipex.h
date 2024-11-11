/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:52:50 by dalebran          #+#    #+#             */
/*   Updated: 2024/11/06 02:29:09 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"
#include <sys/wait.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	***cmd;
	char	**envp;
	int		*pipe_fd;
	pid_t	*pids;
	int		cmd_count;
	char	*limiter;
}			t_pipex;

void		exec_cmd(t_pipex *data, char **cmd, int cmd_index);
void		handle_here_doc(t_pipex *data, char **av);
void		create_pipes(t_pipex *data);
void		execute_commands(t_pipex *data);
void		wait_process(t_pipex *data);
void		close_all_pipes(t_pipex *data);
int			init_pipex2(t_pipex *data, int ac, char **av, char **envp);
int			init_pipex(t_pipex *data, int ac, char **av, char **envp);
void		clear_data(t_pipex *data);
char		*clean_join(char *s1, char *s2);
void		handle_exec_error(char *cmd_path, char *cmd_name, t_pipex *data);
