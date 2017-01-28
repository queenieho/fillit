/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswanson <pswanson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:54:35 by qho               #+#    #+#             */
/*   Updated: 2016/11/26 22:13:26 by pswanson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	*possibletetra(int i)
{
	char			*tetra[20];

	tetra[0] = "####";
	tetra[1] = "#...#...#...#";
	tetra[2] = "###.#";
	tetra[3] = "..#.###";
	tetra[4] = "##...#...#";
	tetra[5] = "#...#...##";
	tetra[6] = "###...#";
	tetra[7] = "#...###";
	tetra[8] = ".#...#..##";
	tetra[9] = "##..#...#";
	tetra[10] = "##..##";
	tetra[11] = "##...##";
	tetra[12] = ".#..##..#";
	tetra[13] = ".##.##";
	tetra[14] = "#...##...#";
	tetra[15] = "###..#";
	tetra[16] = "#...##..#";
	tetra[17] = ".#..###";
	tetra[18] = ".#..##...#";
	tetra[19] = NULL;
	return (tetra[i]);
}

int		arraylen(char **array)
{
	int				i;

	i = -1;
	while (array != NULL && array[++i] != NULL)
		;
	return (i);
}

int		*validtetraminos(char **tetra)
{
	int				i;
	int				j;
	static int		valid[27];

	i = 0;
	if (tetra == NULL)
		return (NULL);
	while (++i <= arraylen(tetra))
	{
		j = -1;
		while (++j < 20)
		{
			if (j == 19)
				return (NULL);
			else if (ft_strstr(tetra[i - 1], possibletetra(j)) != NULL)
			{
				valid[i] = j;
				j = 20;
			}
		}
	}
	valid[0] = i - 1;
	return (valid);
}

void	terror(void)
{
	ft_putendl("error");
}

int		main(int ac, char **av)
{
	int				*tetra;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	if (maketetra(av[1]) == NULL)
	{
		terror();
		return (1);
	}
	if ((tetra = validtetraminos(tetrasplit(maketetra(av[1])))) == NULL)
	{
		terror();
		return (1);
	}
	fillit(tetra);
	return (0);
}
