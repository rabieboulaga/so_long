/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:38:53 by rabie             #+#    #+#             */
/*   Updated: 2024/07/27 19:24:19 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(char **str)
{
	int i;


	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

void check_lines_length(t_data *data)
{
	int i;

	i = 0;
	data->x = ft_strlen(data->map_real[0]);
	while (data->map_real[i])
	{
		if (data->x != ft_strlen(data->map_real[i]))
			safe_exit(0, data, 0);
		i++;
	}
}

void	check_walls_2(t_data *data)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (data->map_real[j])
	{
		if ((data->map_real[j][0] != '1' && data->map_real[j][0]) || 
		(data->map_real[j][data->x - 1] != '1' && data->map_real[j][data->x - 1] != '\0'))
			safe_exit(0, data, 0);
		while(data->map_real[j][i++])
		{
			if (data->map_real[j][i] == 'P')
				data->P++;
			if (data->map_real[j][i] == 'C')
				data->C++;
			if (data->map_real[j][i] == 'E')
				data->E++;		
		}
		i = 0;
		j++;	
	}
	if (data->P != 1 || data->C < 1 || data->E != 1)
		safe_exit(0 , data, 0);
}
void check_walls(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map_real[0][i])
	{
		if (data->map_real[0][i] != '1' && data->map_real[0][i] != '\0')
			safe_exit(0, data, 0);
		i++;
	}
	i = 0;
	while (data->map_real[j])
		j++;
	j--;
	while (data->map_real[j][i])
	{
		if (data->map_real[j][i] != '1' && data->map_real[j][i] != '\0')
			safe_exit(0, data, 0);
		i++;
	}
	check_walls_2(data);
}

void check_map(t_data *data)
{	
	check_lines_length(data);
	
	check_walls(data);
	map_copie(data);
	coordinates(data);
	flood_fill(data->xP, data->yP, data->map_copie);
	find_item(data, 'C');
}
