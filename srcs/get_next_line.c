/*
** get_next_line.c for get_next_line in /home/blerio_h/Rendu/C_Elementary/CPE_2015_getnextline
**
** Made by blerio_h
** Login   <blerio_h@Elitebook-Bleriot>
**
** Started on  Mon Jan  4 15:13:13 2016 blerio_h
** Last update Fri May 27 23:53:06 2016 Reever Valerus
*/

#include "my.h"

static char		*my_alloc(char *str, char *buffer)
{
  t_mydouble		doub;

  doub.i = 0;
  doub.j = 0;
  while (str != NULL && str[doub.i] != 0)
    doub.i += 1;
  while (buffer[doub.j] != 0 && buffer[doub.j] != '\n')
    doub.j += 1;
  doub.tmp = malloc(sizeof(char) * (doub.i + doub.j + 1));
  doub.i = 0;
  while (str != NULL && str[doub.i] != 0 && doub.tmp != NULL)
    {
      doub.tmp[doub.i] = str[doub.i];
      ++doub.i;
    }
  doub.j = 0;
  while (buffer[doub.j] != 0 && buffer[doub.j] != '\n' && doub.tmp != NULL)
    doub.tmp[doub.i++] = buffer[doub.j++];
  if (doub.tmp != NULL)
    doub.tmp[doub.i] = 0;
  free(str);
  return (doub.tmp);
}

static void		modif_buffer(char *buffer, int *k)
{
  int			i;
  int			j;

  i = 0;
  j = 0;
  while (buffer[i] != '\n' && buffer[i] != 0)
    ++i;
  if (buffer[i] == '\n' && buffer[i + 1] == 0)
    *k = -5;
  if (buffer[i] == '\n')
    ++i;
  while (buffer[i] != 0)
    buffer[j++] = buffer[i++];
  while (buffer[j] != 0)
    buffer[j++] = 0;
}

char		*get_next_line(const int fd)
{
  static char	buffer[READ_SIZE + 1];
  char		*str;
  int		i;

  i = 0;
  str = NULL;
  while ((buffer[0] == 0 || i == 0) && i != -5)
    {
      if (buffer == NULL || buffer[0] == 0)
	{
	  if ((i = read(fd, buffer, READ_SIZE)) <= 0)
	    return (str);
	  buffer[READ_SIZE] = 0;
	}
      else
	i = 1;
      str = my_alloc(str, buffer);
      modif_buffer(buffer, &i);
    }
  return (str);
}
