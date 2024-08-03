/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:22:56 by rboulaga          #+#    #+#             */
/*   Updated: 2024/08/03 16:27:22 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void the_end(int nothing, t_data *data, int order)
{

	if (nothing == 1)
		free_map (data->map_copie);
	if (order == 0)
		free_map (data->map_real);
	free (data);
	exit (1);
}

void	map_copie(t_data *data)
{
	int i;

	i = 0;
	data->map_copie = malloc(sizeof(char *) * (data->y + 1));
	while (data->map_real[i])
	{
		data->map_copie[i] = ft_strdupp(data->map_real[i]);
		i++;
	}
	
	data->map_copie[i] = NULL;
}

int remove_newline(char **str)
{
	int i;
	int j;
	int len;

	j = 0;
	len = 0;
	while (str && str[len])
		len++;
	while (str && str[j])
	{
		if (len - 1 == j)
			break;
		i = ft_strlen(str[j]);
		if (i > 1)
			str[j][i - 1] = '\0';
		j++;
	}
	return (len);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
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