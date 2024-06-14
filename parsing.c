/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:59:21 by rboulaga          #+#    #+#             */
/*   Updated: 2024/06/14 05:03:26 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void safe_exit(int nothing)
{
	if (nothing == 0)
	{
		write (2, "Error\n", 7);
		exit (1);
	}
}

int	ft_strncmp(const char *str1, const char *str2, int n)
{
	int     i;
	i = 0;
	
	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void check_path(char *av)
{
	int i;
	int x;
	
	x = 1;
	i = 0;
	while(av[i])
		i++;
	i--;
	while(av[i] != '.')
		i--;
	x = ft_strncmp(&av[i], ".ber", 5);
	if (x != 0)	
		safe_exit(0);
}

void parsing(int ac, char **av, t_data *data)
{
	//int fd;
	//char *safe_map;
	//char *str_map;

	//str_map = NULL;
	if (ac == 2)
	{    
		check_path(av[1]);
		data->fd = open(av[1], O_RDONLY);
		if (data->fd == -1)
			safe_exit(0);    
		data->safe_map = get_next_line(data->fd);
		while (data->safe_map)
		{
			data->str_map = ft_strjoinn(data->str_map, data->safe_map); 
			data->safe_map = get_next_line(data->fd);
		}
		data->safe_map = ft_strjoinn(data->safe_map, data->str_map);
	}   
	else
		safe_exit(0);
}