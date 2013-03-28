/*
** 109titrage.c for 109titrage in /home/benzah_m//svn/git@github.com:1475963/109titrage.git
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Mon Mar 25 14:51:31 2013 marc benzahra
** Last update Thu Mar 28 18:15:56 2013 marc benzahra
*/

#include "titrage.h"
#include "coregnl.h"

double	xmax = 0;

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

void		draw_line(t_ptr *ptr, char *data, double x1, double y1, double x2, double y2)
{
  double	x;
  double	y;
  t_color	color;

  srand(time(NULL));
  color.r = rand() % 256;
  color.g = rand() % 256;
  color.b = rand() % 256;
  y = y1;
  x = x1;
  if (y1 > y2)
    while (y > y2)
      {
	x = x1 + ((x2 - x1) * (y - y1)) / (y2 - y1);
	my_pixel_put_to_image(x, y, data, &color);
	y = y - 1;
      }
  else
    while (y <= y2)
      {
	x = x1 + ((x2 - x1) * (y - y1)) / (y2 - y1);
	my_pixel_put_to_image(x, y, data, &color);
	y = y + 1;
      }
  mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
}

void		draw_line_more(t_ptr *ptr, char *data, double x1, double y1, double x2, double y2)
{
  double	x;
  double	y;
  t_color	color;

  srand(time(NULL));
  color.r = rand() % 256;
  color.g = rand() % 256;
  color.b = rand() % 256;
  y = y1;
  x = x1;
  if (x1 > x2)
    while (x > x2)
      {
	y = y1 + ((y2 - y1) * (x - x1)) / (x2 - x1);
	my_pixel_put_to_image(x, y, data, &color);
	x = x - 1;
      }
  else
    while (x <= x2)
      {
	y = y1 + ((y2 - y1) * (x - x1)) / (x2 - x1);
	my_pixel_put_to_image(x, y, data, &color);
	x = x + 1;
      }
  mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
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

void	draw_voleq(t_ptr *ptr)
{
  mlx_string_put(ptr->mlx, ptr->win, 100 + xmax * 40 - 15, 90, 000255255255, "VolEq");
}

void	draw_graph(t_ptr *ptr)
{
  mlx_string_put(ptr->mlx, ptr->win, 100, 915, 000255255255, "0");
  mlx_string_put(ptr->mlx, ptr->win, 140, 915, 000255255255, "1");
  mlx_string_put(ptr->mlx, ptr->win, 180, 915, 000255255255, "2");
  mlx_string_put(ptr->mlx, ptr->win, 220, 915, 000255255255, "3");
  mlx_string_put(ptr->mlx, ptr->win, 260, 915, 000255255255, "4");
  mlx_string_put(ptr->mlx, ptr->win, 300, 915, 000255255255, "5");
  mlx_string_put(ptr->mlx, ptr->win, 340, 915, 000255255255, "6");
  mlx_string_put(ptr->mlx, ptr->win, 380, 915, 000255255255, "7");
  mlx_string_put(ptr->mlx, ptr->win, 420, 915, 000255255255, "8");
  mlx_string_put(ptr->mlx, ptr->win, 460, 915, 000255255255, "9");
  mlx_string_put(ptr->mlx, ptr->win, 500, 915, 000255255255, "10");
  mlx_string_put(ptr->mlx, ptr->win, 540, 915, 000255255255, "11");
  mlx_string_put(ptr->mlx, ptr->win, 580, 915, 000255255255, "12");
  mlx_string_put(ptr->mlx, ptr->win, 620, 915, 000255255255, "13");
  mlx_string_put(ptr->mlx, ptr->win, 660, 915, 000255255255, "14");
  mlx_string_put(ptr->mlx, ptr->win, 700, 915, 000255255255, "15");
  mlx_string_put(ptr->mlx, ptr->win, 740, 915, 000255255255, "16");
  mlx_string_put(ptr->mlx, ptr->win, 780, 915, 000255255255, "17");
  mlx_string_put(ptr->mlx, ptr->win, 820, 915, 000255255255, "18");
  mlx_string_put(ptr->mlx, ptr->win, 860, 915, 000255255255, "19");
  mlx_string_put(ptr->mlx, ptr->win, 900, 915, 000255255255, "20");
  mlx_string_put(ptr->mlx, ptr->win, 90, 900, 000255255255, "0");
  mlx_string_put(ptr->mlx, ptr->win, 90, 860, 000255255255, "1");
  mlx_string_put(ptr->mlx, ptr->win, 90, 820, 000255255255, "2");
  mlx_string_put(ptr->mlx, ptr->win, 90, 780, 000255255255, "3");
  mlx_string_put(ptr->mlx, ptr->win, 90, 740, 000255255255, "4");
  mlx_string_put(ptr->mlx, ptr->win, 90, 700, 000255255255, "5");
  mlx_string_put(ptr->mlx, ptr->win, 90, 660, 000255255255, "6");
  mlx_string_put(ptr->mlx, ptr->win, 90, 620, 000255255255, "7");
  mlx_string_put(ptr->mlx, ptr->win, 90, 580, 000255255255, "8");
  mlx_string_put(ptr->mlx, ptr->win, 90, 540, 000255255255, "9");
  mlx_string_put(ptr->mlx, ptr->win, 85, 500, 000255255255, "10");
  mlx_string_put(ptr->mlx, ptr->win, 85, 460, 000255255255, "11");
  mlx_string_put(ptr->mlx, ptr->win, 85, 420, 000255255255, "12");
  mlx_string_put(ptr->mlx, ptr->win, 85, 380, 000255255255, "13");
  mlx_string_put(ptr->mlx, ptr->win, 85, 340, 000255255255, "14");
  mlx_string_put(ptr->mlx, ptr->win, 85, 300, 000255255255, "15");
  mlx_string_put(ptr->mlx, ptr->win, 85, 260, 000255255255, "16");
  mlx_string_put(ptr->mlx, ptr->win, 85, 220, 000255255255, "17");
  mlx_string_put(ptr->mlx, ptr->win, 85, 180, 000255255255, "18");
  mlx_string_put(ptr->mlx, ptr->win, 85, 140, 000255255255, "19");
  mlx_string_put(ptr->mlx, ptr->win, 85, 100, 000255255255, "20");
  mlx_string_put(ptr->mlx, ptr->win, 400, 50, 000255255255, "Courbe du pH en fonction du volume");
  mlx_string_put(ptr->mlx, ptr->win, 440, 950, 000255255255, "Volume de soude en mL");
  mlx_string_put(ptr->mlx, ptr->win, 50, 495, 000255255255, "p");
  mlx_string_put(ptr->mlx, ptr->win, 50, 510, 000255255255, "H");
}

int	manage_expose(void *param)
{
  t_ptr	*p;

  p = (t_ptr *)param;
  mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
  draw_graph(p);
  draw_voleq(p);
  return (0);
}

int	manage_key(int keycode, void *param)
{
  if (keycode == 65307)
    exit(0);
  return (0);
}

void		first_option()
{
  char		*buffer;
  char		*x;
  char		*y;
  double	xold = 0;
  double	yold = 0;
  double	res = 0;
  double	ymax = 0;
  int		i;
  int		pos;
  t_ptr		ptr;
  t_data	data;
  t_color	color;

  //init color + mlx
  color.r = 255;
  color.g = 255;
  color.b = 255;
  ptr.mlx = mlx_init();
  ptr.win = mlx_new_window(ptr.mlx, 1000, 1000, "GRAPH");
  ptr.img = mlx_new_image(ptr.mlx, 1000, 1000);
  data.data = mlx_get_data_addr(ptr.img, &data.bpp, &data.sizeline, &data.endian);
  if ((buffer = malloc(BUFF_SIZE)) == NULL)
    exit_error("malloc", "109transfert", "first_option");
  while (strcmp(buffer, "FIN") != 0)
    {
      //recuperation ligne par ligne
      if ((buffer = coregnl(0)) == NULL)
	exit_error("getline", "109titrage.c", "first_option");
      if (strcmp(buffer, "FIN") != 0)
	{
	  //extraction de x et y récuperée
	  if ((x = malloc(BUFF_SIZE)) == NULL)
	    exit_error("malloc", "109transfert", "first_option");
	  i = 0;
	  pos = 0;
	  while (buffer[i] != ';' && buffer[i] != '\0')
	    {
	      x[pos] = buffer[i];
	      pos = pos + 1;
	      i = i + 1;
	    }
	  x[pos] = '\0';
	  if (buffer[i] == ';')
	    i = i + 1;
	  if ((y = malloc(BUFF_SIZE)) == NULL)
	    exit_error("malloc", "109transfert", "first_option");
	  pos = 0;
	  while (buffer[i] != '\0')
	    {
	      y[pos] = buffer[i];
	      pos = pos + 1;
	      i = i + 1;
	    }
	  y[pos] = '\0';
	  //draw des x et y extrait + liaison en ligne
	  my_pixel_put_to_image(100 + atof(x) * 40, 900 - atof(y) * 40, data.data, &color);
	  draw_line(&ptr, data.data, 100 + xold * 40, 900 - yold * 40, 100 + atof(x) * 40, 900 - atof(y) * 40);
	  draw_line_more(&ptr, data.data, 100 + xold * 40, 900 - yold * 40, 100 + atof(x) * 40, 900 - atof(y) * 40);
	  //draw des points de la derivée
	  my_pixel_put_to_image(100 + atof(x) * 40, 900 - res * 40, data.data, &color);
	  //liaison des points en ligne sauf pour la première itération
	  if (res != 0)
	    {
	      draw_line(&ptr, data.data, 100 + xold * 40, 900 - res * 40, 100 + atof(x) * 40, 900 - ((yold - atof(y)) / (xold - atof(x))) * 40);
	      draw_line_more(&ptr, data.data, 100 + xold * 40, 900 - res * 40, 100 + atof(x) * 40, 900 - ((yold - atof(y)) / (xold - atof(x))) * 40);
	    }
	  //recupération de la valeur maximum au fur et à mesure
	  if (res > ymax)
	    {
	      ymax = res;
	      xmax = atof(x);
	    }
	  //affectation resultat + check division par 0
	  if (xold - atof(x) != 0)
	    res = (yold - atof(y)) / (xold - atof(x));
	  //changement des variables pas à pas pour avoir la mémoire de celui d'avant
	  xold = atof(x);
	  yold = atof(y);
	  //free
	  free(x);
	  free(y);
	}
    }
  //obtention + affichage du volume équivalent
  printf("volume équivalent : (%f)\n", xmax);
  mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
  draw_vertical(&ptr, data.data, 100 + xmax * 40, 900, 100 + xmax * 40, 100);
  draw_voleq(&ptr);
  //axe + graduation
  draw_horizontal(&ptr, data.data, 100, 900, 900, 900);
  draw_vertical(&ptr, data.data, 100, 900, 100, 100);
  draw_graph(&ptr);
  //expose key loop
  mlx_expose_hook(ptr.win, manage_expose, (void *)&ptr);
  mlx_key_hook(ptr.win, manage_key, (void *)&ptr);
  mlx_loop(ptr.mlx);
}

void	second_option(int angle)
{
  char		*buffer;
  char		*x;
  char		*y;
  double	xold = 0;
  double	yold = 0;
  double	res = 0;
  double	ymax = 0;
  int		i;
  int		pos;
  t_ptr		ptr;
  t_data	data;
  t_color	color;

  //init color + mlx
  color.r = 255;
  color.g = 255;
  color.b = 255;
  ptr.mlx = mlx_init();
  ptr.win = mlx_new_window(ptr.mlx, 1000, 1000, "GRAPH");
  ptr.img = mlx_new_image(ptr.mlx, 1000, 1000);
  data.data = mlx_get_data_addr(ptr.img, &data.bpp, &data.sizeline, &data.endian);
  if ((buffer = malloc(BUFF_SIZE)) == NULL)
    exit_error("malloc", "109transfert", "first_option");
  while (strcmp(buffer, "FIN") != 0)
    {
      //recuperation ligne par ligne
      if ((buffer = coregnl(0)) == NULL)
	exit_error("getline", "109titrage.c", "first_option");
      if (strcmp(buffer, "FIN") != 0)
	{
	  //extraction de x et y dans la ligne récuperée
	  if ((x = malloc(BUFF_SIZE)) == NULL)
	    exit_error("malloc", "109transfert", "first_option");
	  i = 0;
	  pos = 0;
	  while (buffer[i] != ';' && buffer[i] != '\0')
	    {
	      x[pos] = buffer[i];
	      pos = pos + 1;
	      i = i + 1;
	    }
	  x[pos] = '\0';
	  if (buffer[i] == ';')
	    i = i + 1;
	  if ((y = malloc(BUFF_SIZE)) == NULL)
	    exit_error("malloc", "109transfert", "first_option");
	  pos = 0;
	  while (buffer[i] != '\0')
	    {
	      y[pos] = buffer[i];
	      pos = pos + 1;
	      i = i + 1;
	    }
	  y[pos] = '\0';
	  //draw des x et y extrait + liaison en ligne
	  my_pixel_put_to_image(100 + atof(x) * 40, 900 - atof(y) * 40, data.data, &color);
	  draw_line(&ptr, data.data, 100 + xold * 40, 900 - yold * 40, 100 + atof(x) * 40, 900 - atof(y) * 40);
	  draw_line_more(&ptr, data.data, 100 + xold * 40, 900 - yold * 40, 100 + atof(x) * 40, 900 - atof(y) * 40);
	  //affectation resultat + check division par 0
	  if (xold - atof(x) != 0)
	    res = (yold - atof(y)) / (xold - atof(x));
	  //affichage de l'inclinaison de la tangente en chaque point
	  printf("Degree = (%f)\n", floor(atan(res) * 180 / M_PI));
	  //trouve et trace les tangentes meme plus que 2 pour l'instant
	  if (floor(atan(res) * 180 / M_PI) == angle)
	    {
	      printf("superx = (%f)\tsupery = (%f)\tsuperres = (%f)\n", atof(x), atof(y), res);
	      double	inc = 0;
	      while (inc < 20)
		{
		  if ((res * (inc - atof(x)) + atof(y)) <= 20 && (res * (inc - atof(x)) + atof(y)) >= 0)
		    my_pixel_put_to_image(100 + inc * 40, 900 - (res * (inc - atof(x)) + atof(y)) * 40, data.data, &color);
		  inc = inc + 0.001;
		}
	    }
	  //changement des variables pas à pas pour avoir la mémoire de celui d'avant
	  xold = atof(x);
	  yold = atof(y);
	  //free (IL EN MANQUE FOK IT)
	  free(x);
	  free(y);
	}
    }
  //obtention + affichage du volume équivalent
  /*
  printf("volume équivalent : (%f)\n", xmax);
  mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
  draw_vertical(&ptr, data.data, 100 + xmax * 40, 900, 100 + xmax * 40, 100);
  draw_voleq(&ptr);
  */
  //axes + graduation
  draw_horizontal(&ptr, data.data, 100, 900, 900, 900);
  draw_vertical(&ptr, data.data, 100, 900, 100, 100);
  draw_graph(&ptr);
  //expose key loop
  mlx_expose_hook(ptr.win, manage_expose, (void *)&ptr);
  mlx_key_hook(ptr.win, manage_key, (void *)&ptr);
  mlx_loop(ptr.mlx);
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
