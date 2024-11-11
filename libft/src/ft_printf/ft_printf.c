/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 08:43:08 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/22 20:48:46 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_handler	*initialize_handlers(void)
{
	static t_handler	handlers[256] = {
		NULL
	};

	handlers['s'] = ft_handle_s;
	handlers['c'] = ft_handle_c;
	handlers['p'] = ft_handle_p;
	handlers['d'] = ft_handle_d;
	handlers['i'] = ft_handle_i;
	handlers['u'] = ft_handle_u;
	handlers['x'] = ft_handle_x;
	handlers['X'] = ft_handle_xcaps;
	handlers['%'] = ft_handle_percent;
	return (handlers);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_handler	*handlers;
	int			size;

	size = 0;
	va_start(args, format);
	handlers = initialize_handlers();
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (handlers[(unsigned char)*format])
				size += handlers[(unsigned char)*format](args);
			format++;
		}
		else
		{
			write(1, format, 1);
			format++;
			size++;
		}
	}
	va_end(args);
	return (size);
}
