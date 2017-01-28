/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswanson <pswanson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:15:18 by qho               #+#    #+#             */
/*   Updated: 2016/11/26 17:28:00 by pswanson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

char		*maketetra(char *file);
int			check_newline(char *s);

char		**tetrasplit(char *s);
size_t		tetracount(const char *s, char c);
char		*getnexttetra(const char *str, char del, int windex);

int			*validtetraminos(char **tetra);
int			arraylen(char **array);
char		*possibletetra(int i);

void		terror();

void		fillit(int *tindex);
char		**tetra_fillit(char *s, int h);
char		**createarray(void);
char		init_tetra(char c, int h);

void		print_map(char **map);

int			getwidth(char **tetra);
int			getheight(char **tetra);

char		**solve(char ***tetra, int num);
int			high_sqrt(int n);
char		**map_new(int s);
char		**clean_map(char **map, int size);
int			tetra_in_map(char **map, int size, int i);
int			tryfit_tetra(char **map, char **tetra, int size);
int			try_place(char **tetra, char **map, int x, int y);
char		**put_tetra(char **map, char **tetra, int size);
char		**place(char **tetra, char **map, int x, int y);
char		**remove_tetra(char **map, int i, int size);
int			tryshift_tetra(char **map, char **tetra, int size);
char		**shift_tetra(char **map, char **tetra, int size);
char		**enlarge_map(char **map, int size);

#endif
