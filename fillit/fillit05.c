/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit05.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswanson <pswanson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:38:24 by qho               #+#    #+#             */
/*   Updated: 2016/11/26 21:52:24 by pswanson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char		**remove_tetra(char **map, int i, int size)
{
	int			d[4];

	d[1] = -1;
	d[2] = 50;
	d[3] = 50;
	while (++(d[1]) < size)
	{
		d[0] = -1;
		while (++(d[0]) < size)
		{
			if (map[d[1]][d[0]] == ('A' + i))
			{
				if (d[1] < d[3])
					d[3] = d[1];
				if (d[0] < d[2])
					d[2] = d[0];
				map[d[1]][d[0]] = '.';
			}
		}
	}
	if (d[2] < 50 && map[d[3]][d[2]] >= 'A' && map[d[3]][d[2]] <= 'Z')
		map[d[3]][d[2]] = ft_tolower(map[d[3]][d[2]]);
	else if (d[2] < 50)
		map[d[3]][d[2]] = '#';
	return (map);
}

int			getwidth(char **tetra)
{
	int			x;
	int			y;
	int			result;

	result = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (x >= result && ft_isalpha(tetra[y][x]))
				result = x + 1;
			x++;
		}
		y++;
	}
	return (result);
}

int			getheight(char **tetra)
{
	int			x;
	int			y;
	int			result;

	result = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (y >= result && ft_isalpha(tetra[y][x]))
				result = y + 1;
			x++;
		}
		y++;
	}
	return (result);
}

int			try_place(char **tetra, char **map, int x, int y)
{
	int			i;
	int			j;

	i = -1;
	while (++i < getheight(tetra))
	{
		j = -1;
		while (++j < getwidth(tetra))
			if (ft_isalpha(tetra[i][j]) && (map[y + i][x + j] != '.'))
				return (0);
	}
	return (1);
}

int			tryfit_tetra(char **map, char **tetra, int size)
{
	int			x;
	int			y;

	y = 0;
	while (y <= size - getheight(tetra))
	{
		x = 0;
		while (x <= size - getwidth(tetra))
		{
			if (try_place(tetra, map, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
