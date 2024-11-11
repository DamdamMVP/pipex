/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_handle_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 08:02:26 by dalebran          #+#    #+#             */
/*   Updated: 2024/11/04 22:26:10 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_e_handle_c(va_list args)
{
	unsigned char	char_arg;

	char_arg = (unsigned char)va_arg(args, int);
	ft_putchar_fd(char_arg, 2);
	return (1);
}
