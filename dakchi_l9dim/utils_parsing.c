/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:22:56 by rboulaga          #+#    #+#             */
/*   Updated: 2024/06/13 19:23:08 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bs;
	unsigned char	ps;
	size_t			i;

	bs = (unsigned char *)b;
	ps = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		bs[i] = ps;
		i++;
	}
	return (bs);
}