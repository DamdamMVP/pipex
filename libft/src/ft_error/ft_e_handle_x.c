/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_handle_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:00:46 by dalebran          #+#    #+#             */
/*   Updated: 2024/11/04 22:26:40 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_e_handle_x(va_list args)
{
	unsigned int	number;
	char			*hex_representation;
	char			*tmp;
	int				len;

	number = va_arg(args, unsigned int);
	hex_representation = ft_tobase16(number);
	tmp = hex_representation;
	while (*tmp)
	{
		*tmp = ft_tolower(*tmp);
		tmp++;
	}
	len = ft_strlen(hex_representation);
	ft_putstr_fd(hex_representation, 2);
	free(hex_representation);
	return (len);
}
