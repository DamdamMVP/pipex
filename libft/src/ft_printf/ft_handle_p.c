/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:17:26 by dalebran          #+#    #+#             */
/*   Updated: 2023/10/24 08:38:51 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_p(va_list args)
{
	unsigned long	address;
	char			*hex_address;
	int				len;

	address = (unsigned long)va_arg(args, void *);
	if (address == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	hex_address = ft_tobase16(address);
	len = ft_strlen(hex_address) + 2;
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(hex_address, 1);
	free(hex_address);
	return (len);
}
