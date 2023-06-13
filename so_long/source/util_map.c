/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:34:58 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/13 15:06:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "so_long.h"

// void	read_map(int fd, t_map *map);
// t_bool	is_valid_size(t_uint x, t_uint y);

// t_map	init_map(char *filename)
// {
// 	static t_map	map;

// 	read_map(open(filename, O_RDONLY), &map);
// 	return (map);
// }

// void	read_map(int fd, t_map *map)
// {
// 	char			*line;
// 	static t_uint	x;
// 	static t_uint	y;

// 	line = get_next_line(fd);
// 	if (line)
// 	{
// 		x = ft_strlen(line);
// 		if (ft_strchr(line, '\n'))
// 			x--;
// 		y++;
// 		if (x == map->width || y == 1)
// 		{
// 			map->width = x;
// 			map->height = y;
// 			read_map(fd, map);
// 		}
// 	}
// 	else if (!line && is_valid_size(x, y))
// 			map->map = ft_calloc(map->height, sizeof(char *));
// 	if (map->map)
// 		map->map[y - 1] = line;
// 	else
// 		ft_free(line);
// }

// t_bool	is_valid_size(t_uint x, t_uint y)
// {
// 	return ((x > 2 && y > 4)
// 		|| (x > 3 && y > 3)
// 		|| (x > 4 && y > 2));
// }

// char	ref_tile(char **map, t_coord coord)
// {
// 	return (map[coord.y][coord.x]);
// }

// void	swap_tile(char **map, t_char *chartr, t_coord moved, char target)
// {
// 	map[chartr->coord.y][chartr->coord.x] = EMTY;
// 	map[moved.y][moved.x] = target;
// 	chartr->coord = moved;
// }

void	read_map(int fd, t_map *map, t_uint x, t_uint y);
t_bool	is_valid_size(t_uint x, t_uint y);

t_map	init_map(char *filename)
{
	t_map	map;

	map.map = NULL;
	read_map(open(filename, O_RDONLY), &map, 0, 0);
	return (map);
}

void	read_map(int fd, t_map *map, t_uint x, t_uint y)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
	{
		x = ft_strlen(line);
		if (ft_strchr(line, '\n'))
			x--;
		y++;
		if (x == map->width || y == 1)
		{
			map->width = x;
			map->height = y;
			read_map(fd, map, x, y);
		}
	}
	else if (!line && is_valid_size(x, y))
			map->map = ft_calloc(map->height, sizeof(char *));
	if (map->map)
		map->map[y - 1] = line;
	else
		ft_free(line);
}

t_bool	is_valid_size(t_uint x, t_uint y)
{
	return ((x > 2 && y > 4)
		|| (x > 3 && y > 3)
		|| (x > 4 && y > 2));
}

char	ref_tile(char **map, t_coord coord)
{
	return (map[coord.y][coord.x]);
}

void	swap_tile(char **map, t_char *chartr, t_coord moved, char target)
{
	map[chartr->coord.y][chartr->coord.x] = EMTY;
	map[moved.y][moved.x] = target;
	chartr->coord = moved;
}