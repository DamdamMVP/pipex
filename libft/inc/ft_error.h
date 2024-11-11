/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 08:42:57 by dalebran          #+#    #+#             */
/*   Updated: 2024/10/27 23:02:56 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef int	(*t_handler)(va_list);
int		ft_error(const char *format, ...);
int		ft_e_handle_s(va_list args);
int		ft_e_handle_c(va_list args);
int		ft_e_handle_p(va_list args);
int		ft_e_handle_d(va_list args);
int		ft_e_handle_i(va_list args);
int		ft_e_handle_u(va_list args);
int		ft_e_handle_x(va_list args);
int		ft_e_handle_xcaps(va_list args);
int		ft_e_handle_percent(va_list args);

#endif
