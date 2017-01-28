/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswanson <pswanson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:22:01 by qho               #+#    #+#             */
/*   Updated: 2016/11/26 17:34:54 by pswanson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void		print_map(char **map)
{
	int				x;
	int				y;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
			ft_putchar(map[y][x]);
		ft_putchar('\n');
	}
}

char		init_tetra(char c, int h)
{
	if (c == '#')
		return (h + 'A');
	else
		return ('.');
}

char		**createarray(void)
{
	char			**array;
	int				row;

	row = 0;
	array = malloc(4 * sizeof(*array));
	while (row < 4)
		array[row++] = malloc(5 * sizeof(**array));
	return (array);
}

char		**tetra_fillit(char *s, int h)
{
	char			**tetra;
	int				x;
	int				y;

	y = 0;
	tetra = createarray();
	while (*s != '\0' && y < 4)
	{
		x = 0;
		while (*s != '\0' && x < 4)
			tetra[y][x++] = init_tetra(*(s++), h);
		if (*s != '\0' && x == 4)
			tetra[y++][x] = '\0';
	}
	while (y < 4)
	{
		while (x < 4)
			tetra[y][x++] = '.';
		tetra[y++][x] = '\0';
		x = 0;
	}
	return (tetra);
}

void		fillit(int *tindex)
{
	int				i;
	char			***tetra;
	char			**map;

	if ((tetra = (char ***)malloc(sizeof(char*) * 5 *
		(tindex[0] + 1))) == NULL)
		return ;
	i = 0;
	while (i < tindex[0])
	{
		tetra[i] = tetra_fillit(possibletetra(tindex[i + 1]), i);
		i++;
	}
	map = solve(tetra, tindex[0]);
	print_map(map);
	free(map);
	free(tetra);
}
