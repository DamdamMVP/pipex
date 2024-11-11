/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:35:59 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/29 00:45:51 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**copy_map(char **map)
{
	int		i;
	int		row;
	char	**copy_map;

	row = calc_row_map(map);
	copy_map = (char **)malloc(sizeof(char *) * (row + 1));
	if (!copy_map)
		return (free_map(copy_map), NULL);
	ft_memset(copy_map, 0, sizeof(char *) * (row + 1));
	i = 0;
	while (i < row)
	{
		copy_map[i] = ft_strdup(map[i]);
		i++;
	}
	copy_map[row] = NULL;
	return (copy_map);
}
