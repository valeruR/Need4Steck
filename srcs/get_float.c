/*
** get_float.c for n4s in /home/valeru_r/rendu/Prog_Elem/Need_for_Stek/CPE_2015_n4s/srcs
** 
** Made by Reever Valerus
** Login   <valeru_r@epitech.net>
** 
** Started on  Sat May 28 11:35:16 2016 Reever Valerus
** Last update Sat May 28 17:36:33 2016 Reever Valerus
*/

#include "my.h"

static int	my_get_nbr(char *str, int *idx)
{
  int		value;
  int		pos;
  int		i;

  i = *idx;
  value = 0;
  pos = 1;
  while (str[i] != '.' && str[i])
    {
      value = (value * pos) + (str[i] - '0');
      pos = 10;
      i++;
    }
  *idx = i;
  return (value);
}

double		get_float(char *str, int i, int end)
{
  double	value;
  int		pos;

  value = my_get_nbr(str, &i);
  i++;
  pos = 1;
  while (i < end)
    {
      value = value + ((str[i] - '0') * pow(10, -pos));
      pos++;
      i++;
    }
  return (value);
}
