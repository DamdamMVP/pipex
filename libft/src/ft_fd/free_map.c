/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:19:21 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/29 00:45:05 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

void	free_map(char **map)
{
	int	i;
	int	height;

	if (!map)
		return ;
	height = map_height(map);
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
