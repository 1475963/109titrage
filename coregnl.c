/*
** get_next_line_norme.c for get_next_line in /home/benzah_m//projets/get_next_line
** 
** Made by marc benzahra
** Login   <benzah_m@epitech.net>
** 
** Started on  Wed Nov 21 01:06:50 2012 marc benzahra
** Last update Mon Mar 25 15:52:14 2013 marc benzahra
*/

#include "coregnl.h"

void	put_in_line(char *line, char *buffer, int *count)
{
  int	i;

  i = 0;
  while (buffer != NULL && buffer[*count] != '\0' && buffer[*count] != '\n')
    {
      line[i] = buffer[*count];
      i = i + 1;
      *count = *count + 1;
    }
  *count = *count + 1;
  line[i] = '\0';
}

int	my_line_len(int i, char *buff)
{
  int	mem;

  mem = i;
  if (buff != NULL && buff[i] != '\0')
    while (buff[i] != '\0' && buff[i] != '\n')
      i = i + 1;
  return (i - mem);
}

char		*coregnl(const int fd)
{
  char		*line;
  int		size;
  static char	buffer[BUFF_SIZE + 1];
  static int	i;

  if (((i == 0 && (size = read(fd, buffer, BUFF_SIZE)) == -1) && size == 0)
      || buffer[i] == '\0')
    return (NULL);
  if ((line = malloc((my_line_len(i, buffer) + 1) * sizeof(char))) == NULL)
    return (NULL);
  put_in_line(line, buffer, &i);
  if (i >= BUFF_SIZE)
    i = 0;
  return (line);
}
