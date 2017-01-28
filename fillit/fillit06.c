/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit06.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswanson <pswanson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:43:24 by qho               #+#    #+#             */
/*   Updated: 2016/11/26 17:14:41 by pswanson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char		**enlarge_map(char **map, int size)
{
	free(map);
	map = map_new(size);
	return (map);
}

char		**place(char **tetra, char **map, int x, int y)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < getheight(tetra))
	{
		while (j < getwidth(tetra))
		{
			if (ft_isalpha(tetra[i][j]))
			{
				map[y + i][x + j] = tetra[i][j];
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

char		**put_tetra(char **map, char **tetra, int size)
{
	int			x;
	int			y;

	if (tetra == NULL || tetra == '\0')
		return (map);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (try_place(tetra, map, x, y))
			{
				map = place(tetra, map, x, y);
				return (map);
			}
			x++;
		}
		y++;
	}
	return (map);
}

char		**shift_tetra(char **map, char **tetra, int size)
{
	int			x;
	int			y;
	int			flag;

	flag = 0;
	y = 0;
	while (y <= size - getheight(tetra))
	{
		x = 0;
		while (x <= size - getwidth(tetra))
		{
			if (map[y][x] > 90 && flag == 0)
				flag = 1;
			else if (map[y][x] == '#' && flag == 0)
				flag = 1;
			else if (flag && try_place(tetra, map, x, y))
				return (place(tetra, map, x, y));
			x++;
		}
		y++;
	}
	return (map);
}

int			tryshift_tetra(char **map, char **tetra, int size)
{
	int			x;
	int			y;
	int			flag;

	y = 0;
	flag = 0;
	while (y <= size - getheight(tetra))
	{
		x = 0;
		while (x <= size - getwidth(tetra))
		{
			if (map[y][x] > 90 && flag == 0)
				flag = 1;
			else if (map[y][x] == '#' && flag == 0)
				flag = 1;
			else if (flag && try_place(tetra, map, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
