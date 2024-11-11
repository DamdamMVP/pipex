/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:08:12 by dalebran          #+#    #+#             */
/*   Updated: 2024/11/02 05:04:22 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	verif_and_calc_map(int fd, int *rows, int *cols)
{
	char	*current;
	int		line_length;

	*rows = 0;
	current = ft_get_next_line(fd);
	if (!current)
		return (ft_error("Error reading file or empty file.\n"), 0);
	line_length = ft_strlen(current);
	if (current[line_length - 1] == '\n')
		line_length--;
	*cols = line_length;
	while (current)
	{
		line_length = ft_strlen(current);
		if (current[line_length - 1] == '\n')
			line_length--;
		if (line_length != *cols)
			return (free(current), ft_error("The map is not a rect.\n"), 0);
		(*rows)++;
		free(current);
		current = ft_get_next_line(fd);
	}
	return (1);
}

char	**allocate_map(int rows)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!map)
	{
		ft_error("Memory allocation error.\n");
		return (NULL);
	}
	return (map);
}

int	fill_map(int fd, char **map, int rows, int cols)
{
	char	*current;
	int		i;

	i = 0;
	current = ft_get_next_line(fd);
	while (i < rows && current)
	{
		map[i] = ft_substr(current, 0, cols);
		if (!map[i])
		{
			free(current);
			free_map(map);
			ft_error("Memory allocation error.\n");
			return (0);
		}
		free(current);
		current = ft_get_next_line(fd);
		i++;
	}
	map[rows] = NULL;
	return (1);
}

char	**read_map(const char *filename)
{
	char	**map;
	int		rows;
	int		cols;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_error("Error opening file.\n"), NULL);
	if (!verif_and_calc_map(fd, &rows, &cols))
		return (close(fd), NULL);
	close(fd),
	map = allocate_map(rows);
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_error("Error opening file.\n"), free_map(map), NULL);
	if (!fill_map(fd, map, rows, cols))
		return (close(fd), free_map(map), NULL);
	return (map);
}
