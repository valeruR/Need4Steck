/*
** my.h for n4s in /home/valeru_r/rendu/Prog_Elem/Need_for_Stek/CPE_2015_n4s
** 
** Made by Reever Valerus
** Login   <valeru_r@epitech.net>
** 
** Started on  Fri May 27 17:16:18 2016 Reever Valerus
** Last update Sat May 28 18:49:00 2016 Reever Valerus
*/

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "commands.h"

# ifndef MY_H_
#  define MY_H_

void		my_putchar(char c);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_put_nbr(int nb);
int		my_put_float(float nb);
int		my_getnbr(char *str);
char		*get_next_line(int fd);
double		get_float(char *str, int i,int end);
int		get_lidar(char *str, float lidar[2]);

# endif
