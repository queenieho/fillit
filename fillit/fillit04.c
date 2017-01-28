/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswanson <pswanson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:32:53 by qho               #+#    #+#             */
/*   Updated: 2016/11/26 21:58:02 by pswanson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int			tetra_in_map(char **map, int size, int i)
{
	int			x;
	int			y;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
			if (map[y][x] == ('A' + i))
				return (1);
	}
	return (0);
}

char		**clean_map(char **map, int size)
{
	int			x;
	int			y;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			if (map[y][x] == '#')
				map[y][x] = '.';
			else if (map[y][x] > 90)
				map[y][x] = ft_toupper(map[y][x]);
		}
	}
	return (map);
}

char		**map_new(int s)
{
	char		**map;
	int			i;
	int			j;

	if ((map = (char **)ft_memalloc(sizeof(char *) * (s + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < s)
	{
		map[i] = ft_strnew(s);
		j = -1;
		while (++j < s)
			map[i][j] = '.';
	}
	return (map);
}

int			high_sqrt(int n)
{
	int			size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

char		**solve(char ***tetra, int num)
{
	char		**map;
	int			s;
	int			i;

	s = high_sqrt(num * 4);
	map = map_new(s);
	i = 0;
	while (tetra[i])
	{
		map = clean_map(map, s);
		if (tetra_in_map(map, s, i) == 0 && tryfit_tetra(map, tetra[i], s))
			map = put_tetra(map, tetra[i++], s);
		else
		{
			map = remove_tetra(map, i, s);
			if (tryshift_tetra(map, tetra[i], s))
				map = shift_tetra(map, tetra[i++], s);
			else if (tryshift_tetra(map, tetra[i], s) == 0 && i == 0)
				map = enlarge_map(map, ++s);
			else
				i--;
		}
	}
	return (map);
}
