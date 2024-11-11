/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 08:43:21 by dalebran          #+#    #+#             */
/*   Updated: 2023/10/24 08:32:18 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_s(va_list args)
{
	char	*str_arg;
	int		len;

	str_arg = va_arg(args, char *);
	if (!str_arg)
		str_arg = "(null)";
	len = ft_strlen(str_arg);
	ft_putstr_fd(str_arg, 1);
	return (len);
}
