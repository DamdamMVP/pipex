/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 08:02:26 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/22 07:11:22 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_c(va_list args)
{
	unsigned char	char_arg;

	char_arg = (unsigned char)va_arg(args, int);
	ft_putchar_fd(char_arg, 1);
	return (1);
}
