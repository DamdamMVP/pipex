/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 08:43:08 by dalebran          #+#    #+#             */
/*   Updated: 2024/11/05 00:57:00 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_handler	*initialize_e_handlers(void)
{
	static t_handler	handlers[256] = {
		NULL
	};

	handlers['s'] = ft_e_handle_s;
	handlers['c'] = ft_e_handle_c;
	handlers['p'] = ft_e_handle_p;
	handlers['d'] = ft_e_handle_d;
	handlers['i'] = ft_e_handle_i;
	handlers['u'] = ft_e_handle_u;
	handlers['x'] = ft_e_handle_x;
	handlers['X'] = ft_e_handle_xcaps;
	handlers['%'] = ft_e_handle_percent;
	return (handlers);
}

int	ft_error(const char *format, ...)
{
	va_list		args;
	t_handler	*handlers;
	int			size;

	size = 0;
	va_start(args, format);
	handlers = initialize_e_handlers();
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
			write(2, format, 1);
			format++;
			size++;
		}
	}
	va_end(args);
	return (size);
}
