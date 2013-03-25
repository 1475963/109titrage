/*
** 109titrage.c for 109titrage in /home/benzah_m//svn/git@github.com:1475963/109titrage.git
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Mon Mar 25 14:51:31 2013 marc benzahra
** Last update Mon Mar 25 15:11:14 2013 marc benzahra
*/

#include "titrage.h"

void	exit_error(char *function, char *file, char *block)
{
  printf("/!\\ %s failed /!\\\nfile : %s\nfunction : %s\n", function, file, block);
  exit(EXIT_FAILURE);
}

void	exit_write(char *str)
{
  printf("%s\n", str);
  exit(EXIT_FAILURE);
}

void    my_pixel_put_to_image(int x, int y, char *data, t_color *color)
{
  int   xmem;

  xmem = (4 * (1000 * y)) + (4 * x);
  data = data + xmem;
  data[0] = color->r;
  data[1] = color->g;
  data[2] = color->b;
}

void		draw_horizontal(t_ptr *ptr, char *data, double x1, double y1, double x2, double y2)
{
  double	x;
  double	mem;
  t_color	color;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  x = x1;
  if (y1 == y2)
    {
      if (x > x2)
	{
	  mem = x;
	  x = x2;
	  x2 = mem;
	}
      while (x <= x2)
	{
	  my_pixel_put_to_image(x, y1, data, &color);
	  x = x + 1;
	}
      mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
    }
}

void		draw_vertical(t_ptr *ptr, char *data, double x1, double y1, double x2, double y2)
{
  double	y;
  t_color	color;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  if (x1 == x2)
    {
      y = y1;
      if (y1 < y2)
	{
	  y = y2;
	  y2 = y1;
	}
      while (y >= y2)
	{
	  my_pixel_put_to_image(x1, y, data, &color);
	  y = y - 1;
	}
      mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
    }
}

void	draw_graph(t_ptr *ptr)
{
  mlx_string_put(ptr->mlx, ptr->win, 100, 915, 000255255255, "-2.0");
  mlx_string_put(ptr->mlx, ptr->win, 200, 915, 000255255255, "-1.5");
  mlx_string_put(ptr->mlx, ptr->win, 300, 915, 000255255255, "-1.0");
  mlx_string_put(ptr->mlx, ptr->win, 400, 915, 000255255255, "-0.5");
  mlx_string_put(ptr->mlx, ptr->win, 500, 915, 000255255255, "0.0");
  mlx_string_put(ptr->mlx, ptr->win, 600, 915, 000255255255, "0.5");
  mlx_string_put(ptr->mlx, ptr->win, 700, 915, 000255255255, "1.0");
  mlx_string_put(ptr->mlx, ptr->win, 800, 915, 000255255255, "1.5");
  mlx_string_put(ptr->mlx, ptr->win, 900, 915, 000255255255, "2");
  mlx_string_put(ptr->mlx, ptr->win, 75, 900, 000255255255, "-2.0");
  mlx_string_put(ptr->mlx, ptr->win, 75, 800, 000255255255, "-1.5");
  mlx_string_put(ptr->mlx, ptr->win, 75, 700, 000255255255, "-1.0");
  mlx_string_put(ptr->mlx, ptr->win, 75, 600, 000255255255, "-0.5");
  mlx_string_put(ptr->mlx, ptr->win, 80, 500, 000255255255, "0.0");
  mlx_string_put(ptr->mlx, ptr->win, 80, 400, 000255255255, "0.5");
  mlx_string_put(ptr->mlx, ptr->win, 80, 300, 000255255255, "1.0");
  mlx_string_put(ptr->mlx, ptr->win, 80, 200, 000255255255, "1.5");
  mlx_string_put(ptr->mlx, ptr->win, 80, 100, 000255255255, "2.0");
}

int	manage_expose(void *param)
{
  t_ptr	*p;

  p = (t_ptr *)param;
  mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
  draw_graph(p);
  return (0);
}

int	manage_key(int keycode, void *param)
{
  if (keycode == 65307)
    exit(0);
  return (0);
}

void	first_option()
{
}

void	second_option()
{
}

void	check_arg(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    if (str[i] >= '0' && str[i] <= '9')
      i = i + 1;
    else
      exit_write("Please put correct arguments");
}

int	check_angle(int angle)
{
  if (angle >= 10 && angle <= 80)
    return (angle);
  else
    exit_write("Please put correct arguments");
}

void	main(int ac, char **av)
{
  if (ac == 1)
    first_option();
  else if (ac == 2)
    {
      check_arg(av[1]);
      second_option(check_angle(atoi(av[1])));
    }
  else
    exit_write("Usage :\t./109titrage\t\tWithout arguments\n\t./109titrage [n]\tn is an angle between 10 and 80 degrees without comma");
}
