/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobase16.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:40:18 by dalebran          #+#    #+#             */
/*   Updated: 2023/10/24 09:02:22 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tobase16(unsigned long nbr)
{
	char			*base;
	char			*hex;
	unsigned long	tmp;
	int				len;

	base = "0123456789abcdef";
	len = 0;
	tmp = nbr;
	if (nbr == 0)
		len = 1;
	while (tmp)
	{
		tmp /= 16;
		len++;
	}
	hex = (char *)malloc(sizeof(char) * (len + 1));
	if (!hex)
		return (NULL);
	hex[len] = '\0';
	while (len--)
	{
		hex[len] = base[nbr % 16];
		nbr /= 16;
	}
	return (hex);
}
