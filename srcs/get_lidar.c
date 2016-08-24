/*
** get_lidar.c for get_lidar in /home/blerio_h/Rendu/C_Elementary/CPE_2015_n4s
**
** Made by Harold Blériot
** Login   <blerio_h@epitech.net>
**
** Started on  Mon May  2 16:34:07 2016 Harold Blériot
** Last update Sun May 29 23:22:04 2016 Reever Valerus
*/

#include "my.h"

static int	get_start(const char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i] != 0)
    if (str[i++] == ':')
      if (++j == 3)
	return (i);
  return (-1);
}

static void	get_avg(const float tab[32], float lidar[2])
{
  int		i;
  double	avg;

  i = 0;
  avg = 0.0;
  while (i < 32)
    {
      avg += tab[i];
      if (i == 14)
	{
	  lidar[0] = avg / 16;
	  avg = 0;
	}
      i++;
    }
  lidar[1] = avg / 16;
}

static int	get_limit(const char *str, int i)
{
  while (str[i] != 0 && str[i] != ':')
    {
      if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
	return (i);
      ++i;
    }
  return (i);
}

static int	check_tab(float tab[32])
{
  int		i;
  int		count_inf;
  int		count_sup;

  i = 0;
  count_inf = 0;
  count_sup = 0;
  while (i < 32)
    {
      if (tab[i] < 50)
	count_inf++;
      i++;
    }
  if (count_inf >= 32)
    return (-1);
  else if (tab[0] >= 430 & tab[31] >= 430)
    return (-2);
  return (0);
}

int		get_lidar(char *str, float lidar[2])
{
  int		i;
  int		j;
  float		tab[32];
  int		check;

  if ((i = get_start(str)) == -1)
    return (1);
  j = 0;
  while (j < 32)
    {
      tab[j++] = get_float(str, i, get_limit(str, i));
      while (str[i] != ':')
	++i;
      ++i;
    }
  if ((check = check_tab(tab)) == 0)
      get_avg(tab, lidar);
  else
    return (check);
  return (0);
}
