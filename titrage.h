/*
** titrage.h for titrage in /home/benzah_m//svn/git@github.com:1475963/109titrage.git
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Mon Mar 25 15:06:25 2013 marc benzahra
** Last update Mon Mar 25 15:08:43 2013 marc benzahra
*/

#ifndef TITRAGE_H_
# define TITRAGE_H_
# include <math.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <string.h>

struct s_ptr
{
  void	*mlx;
  void	*win;
  void	*img;
};

typedef struct s_ptr t_ptr;

struct s_data
{
  int	bpp;
  int	sizeline;
  int	endian;
  char	*data;
};

typedef struct s_data t_data;

struct s_color
{
  int	r;
  int	g;
  int	b;
};

typedef struct s_color t_color;

void	main(int ac, char **av);

#endif /* !TITRAGE_H_ */
