/*
** main.c for main in /home/blerio_h/Rendu/C_Elementary/CPE_2015_n4s
**
** Made by Harold Blériot
** Login   <blerio_h@PC-Ubuntech-NEO>
**
** Started on  Tue May 17 13:09:34 2016 Harold Blériot
** Last update Sun May 29 23:42:01 2016 Reever Valerus
*/

#include "my.h"

static float	return_wheel(float tab[2], float *speed)
{
  int		c;
  float		value;

  *speed = 0.2;
  c = (tab[1] > tab[0]) ? 1 : 0;
  if ((tab[0] <= 150 && tab[1] > 300)
      || (tab[0] > 300 && tab[1] <= 150))
      return (value = (c == 1) ? (0.2 * (-1)) : 0.2);
  if (tab[0] <= 200 || tab[1] <= 200)
      return (value = (c == 1) ? (0.8 * (-1)) : 0.8);
  if (tab[0] <= 300 || tab[1] <= 300)
      return (value = (c == 1) ? (0.6 * (-1)) : 0.6);
  else if (tab[0] <= 500 || tab[1] <= 500)
      return (value = (c == 1) ? (0.4 * (-1)) : 0.4);
  return (value = (c == 1) ? (0.1 * (-1)) : 0.1);
}

static int	set_direction(float *wheel, float *speed)
{
  float	lidar[2];
  char	*s;

  my_putstr(GET_INFO);
  s = get_next_line(0);
  if (get_lidar(s, lidar) == -2)
    {
      *wheel = *wheel - *wheel;
      *speed = 0.8;
    }
  else
      *wheel = return_wheel(lidar, speed);
  my_putstr("WHEELS_DIR:");
  my_put_float(*wheel);
  my_putchar('\n');
  s = get_next_line(0);
  free(s);
  my_putstr("CAR_FORWARD:");
  my_put_float(*speed);
  my_putchar('\n');
  s = get_next_line(0);
  free(s);
}

int	main()
{
  float	wheel;
  float	speed;
  int	i;
  char	*s;

  i = 0;
  write(1, "START_SIMULATION\n", 17);
  s = get_next_line(0);
  free(s);
  speed = 0;
  wheel = 0;
  while (42)
    set_direction(&wheel, &speed);
  return (0);
}
