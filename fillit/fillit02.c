/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswanson <pswanson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:11:46 by qho               #+#    #+#             */
/*   Updated: 2016/11/26 21:35:44 by pswanson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char		*getnexttetra(const char *str, char del, int windex)
{
	char			*new;
	int				i;

	while (windex > 0 && *str != '\0')
	{
		if (*str == del && *(str + 1) == del)
			windex--;
		str++;
	}
	i = 0;
	if ((new = malloc(sizeof(char) * 17)) == NULL)
		return (NULL);
	while (i <= 15 && *str != '\0')
	{
		if (*str != del)
			new[i++] = *(str++);
		else
			str++;
	}
	new[i] = '\0';
	return (new);
}

size_t		tetracount(const char *s, char c)
{
	size_t			num;
	int				lb;

	num = 0;
	lb = 0;
	while (*s != '\0')
	{
		if (*s == '#')
			lb++;
		if (*s != '.' && *s != '#' && *s != '\n')
			return (0);
		if (*s != c && (*(s + 1) == c && (*(s + 2) == '\0' || *(s + 2) == c)))
		{
			num++;
			if (lb != 4)
				return (0);
			lb = 0;
		}
		s++;
	}
	return (num);
}

char		**tetrasplit(char *s)
{
	char			**str;
	size_t			num;
	size_t			i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(num = tetracount(s, '\n')))
		return (NULL);
	if ((str = (char **)malloc(sizeof(char *) * (num + 1))) == NULL)
		return (NULL);
	while (i < num)
	{
		str[i] = getnexttetra(s, '\n', i);
		if (str[i] == NULL)
			return (NULL);
		i++;
	}
	str[i] = NULL;
	return (str);
}

int			check_newline(char *s)
{
	int				i;
	int				t;

	i = 0;
	t = 0;
	while (s[i])
	{
		if ((s[i] == '\n') && (s[i - 1] == '\n'))
			t++;
		if ((s[i] == '\n') && (s[i - 1] != '\n') && ((i + 1 - t) % 5 != 0))
			return (1);
		if ((s[i] == '\n') && (s[i - 1] == '\n') && ((i + 1) % 21 != 0))
			return (1);
		i++;
	}
	if ((i + 1) % 21 != 0)
		return (1);
	return (0);
}

char		*maketetra(char *file)
{
	int				fd;
	char			buf[642];
	char			*tetra;
	size_t			i;

	i = -1;
	fd = open(file, O_RDONLY);
	while (read(fd, &buf[++i], 1) && i < 642)
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (NULL);
	close(fd);
	tetra = ft_strnew(i);
	ft_strncpy(tetra, buf, i);
	if (check_newline(tetra))
	{
		free(tetra);
		return (NULL);
	}
	return (tetra);
}
