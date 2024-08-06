/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:59:21 by rboulaga          #+#    #+#             */
/*   Updated: 2024/08/06 16:19:48 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void safe_exit(int nothing, t_data *data, int order)
{
	if (nothing == 1)
		free_map (data->map_copie);
	if (order == 0)
		free_map (data->map_real);
	free (data);
	write (2, "Error\n", 7);
	exit (1);
}

int	ft_strncmp(const char *str1, const char *str2, int n)
{
	int     i;
	i = 0;

	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}

void check_path(char *av, t_data *data)
{
	int i;

	i = 0;
	while (av[i])
		i++;
	i--;
	while (av[i] != '.')
		i--;
	if ((!av[i - 1]) || av[i - 1] == '/')
		safe_exit (0, data, 1);
	if (ft_strncmp(&av[i], ".ber", 5) != 0)
		safe_exit (0, data, 1);
}

int	filesize(char *file, t_data *data)
{
	int i;
	int fd;
	char *str;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		safe_exit(0, data, 1);
	str = get_next_line(fd);
	i++;
	while (str)
	{
		free (str);
		i++;
		str = get_next_line(fd);
	}
	return (i);
}

void parsing(int ac, char **av, t_data *data)
{
	if (ac == 2)
	{
		int i;
		int len;

		i = 0;
		check_path(av[1], data);
		len = filesize(av[1], data);
		data->fd = open(av[1], O_RDONLY);
		if (data->fd == -1)
			safe_exit(0, data, 1);
		data->map_real = malloc(sizeof(char *) * len);
		data->map_real[i] = get_next_line(data->fd);
		while (data->map_real[i])
		{		
			i++;
			data->map_real[i] = get_next_line(data->fd);	
		}
		data->y = remove_newline(data->map_real);
	}
	else
		safe_exit(0, data, 1);
	check_map(data);
}
