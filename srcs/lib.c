/*
** lib.c for n4s in /home/valeru_r/rendu/Prog_Elem/Need_for_Stek/CPE_2015_n4s/srcs
** 
** Made by Reever Valerus
** Login   <valeru_r@epitech.net>
** 
** Started on  Sat May 28 14:48:52 2016 Reever Valerus
** Last update Sun May 29 23:06:33 2016 Reever Valerus
*/

#include "my.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int		my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0 && nb <= 9)
    my_putchar(nb + 48);
  else
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
      return (0);
    }
  return (nb);
}

int		my_put_float(float nb)
{
  int		value;

  if (nb >= 1 || nb < -1)
    {
      value = nb;
      my_put_nbr(value);
      nb = (nb - value) * 10;
    }
  else
    {
      if (nb < 0)
	{
	  my_putchar('-');
	  nb = (nb - value) * 100 * (-1);
	}
      else
	nb = (nb - value) * 100;
      my_putchar('0');
      value = 0;
    }
  my_putchar('.');
  my_put_nbr(nb);
}
